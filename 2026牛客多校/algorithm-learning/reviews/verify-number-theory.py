"""Independent oracles for the archived learner code and formal templates."""
import argparse
from fractions import Fraction
import json
import math
from pathlib import Path
import random
import subprocess


def run(command, data=None):
    result = subprocess.run(command, input=data, text=True, encoding="utf-8",
                            errors="replace", capture_output=True, check=True)
    return result.stdout.splitlines()


def radical_oracle(n):
    if n == 0:
        return 0, 1
    # Independent of prime exponent extraction: find the largest square divisor.
    for outside in range(math.isqrt(n), 0, -1):
        if n % (outside * outside) == 0:
            return outside, n // (outside * outside)
    raise AssertionError(n)


def fraction_text(value):
    if value.denominator == 1:
        return str(value.numerator)
    return f"{value.numerator}/{value.denominator}"


def equation_oracle(a, b, c):
    delta = b * b - 4 * a * c
    if delta < 0:
        return "NO"
    k = math.isqrt(delta)
    if k * k == delta:
        return fraction_text(max(Fraction(-b + k, 2 * a),
                                 Fraction(-b - k, 2 * a)))
    outside, inside = radical_oracle(delta)
    q1 = Fraction(-b, 2 * a)
    q2 = Fraction(outside, 2 * abs(a))
    prefix = fraction_text(q1) + "+" if q1 else ""
    coefficient = f"{q2.numerator}*" if q2.numerator != 1 else ""
    denominator = f"/{q2.denominator}" if q2.denominator != 1 else ""
    return f"{prefix}{coefficient}sqrt({inside}){denominator}"


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--compiler", required=True)
    parser.add_argument("--template-dir", required=True)
    args = parser.parse_args()
    here = Path(__file__).resolve().parent
    build = here / ".build"
    build.mkdir(exist_ok=True)
    template_binary = build / "number-theory-verification.exe"
    equation_binary = build / "quadratic-larger-root.exe"
    flags = ["-std=c++11", "-O2", "-Wall", "-Wextra", "-pedantic"]
    run([args.compiler, *flags, "-I", str(Path(args.template_dir).resolve()),
         str(here / "number-theory-verification.cpp"), "-o", str(template_binary)])
    run([args.compiler, *flags, str(here / "quadratic-larger-root.cpp"),
         "-o", str(equation_binary)])

    commands, expected = [], []
    gcd_count = fraction_count = 0
    for a in range(-30, 31):
        for b in range(-30, 31):
            commands.append(f"gcd {a} {b}")
            expected.append(str(math.gcd(a, b)))
            gcd_count += 1
            if b:
                value = Fraction(a, b)
                commands.append(f"fraction {a} {b}")
                expected.append(f"{value.numerator} {value.denominator}")
                fraction_count += 1

    roots = list(range(10001)) + [5000000, 999983, 1000000, 2147483647]
    for n in roots:
        commands.append(f"sqrt {n}")
        outside, inside = radical_oracle(n)
        expected.append(f"{outside} {inside}")
    actual = run([str(template_binary)], "\n".join(commands) + "\n")
    assert len(actual) == len(expected), (len(actual), len(expected))
    for command, got, want in zip(commands, actual, expected):
        assert got == want, (command, got, want)

    sample = [(1,-1,0),(-1,-1,-1),(1,-2,1),(1,5,4),(4,4,1),
              (1,0,-432),(1,-3,1),(2,-4,1),(1,7,1)]
    sample_output = ["1","NO","1","-1","-1/2","12*sqrt(3)",
                     "3/2+sqrt(5)/2","1+sqrt(2)/2","-7/2+3*sqrt(5)/2"]
    cases = list(sample)
    cases += [(a,b,c) for a in range(-7,8) if a
              for b in range(-7,8) for c in range(-7,8)]
    rng = random.Random(20261016)
    for _ in range(1000):
        a = rng.choice([-1,1]) * rng.randint(1,1000)
        cases.append((a,rng.randint(-1000,1000),rng.randint(-1000,1000)))
    cases += [(1,-2,-7),(1,2,-7),(1,0,-12),(-1,3,-2),(1000,1000,-1000)]
    data = f"{len(cases)} 1000\n" + "\n".join(" ".join(map(str,c)) for c in cases) + "\n"
    actual = run([str(equation_binary)], data)
    assert len(actual) == len(cases), (len(actual),len(cases))
    assert actual[:9] == sample_output, actual[:9]
    for case, got in zip(cases, actual):
        want = equation_oracle(*case)
        assert got == want, (case,got,want)
        assert not any(ch.isspace() for ch in got), (case,got)
    report = {
        "date": "2026-10-16", "status": "passed", "language_standard": "C++11",
        "gcd_cases": gcd_count, "fraction_cases": fraction_count,
        "radical_cases": len(roots), "equation_cases": len(cases),
        "official_sample_lines": 9, "online_verdict": None,
        "oracles": ["Python math.gcd", "Python fractions.Fraction",
                    "largest square divisor enumeration", "exact rational/symbolic root formatting"],
        "seed": 20261016,
    }
    (here / "number-theory-verification.json").write_text(
        json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(report, ensure_ascii=False))


if __name__ == "__main__":
    main()
