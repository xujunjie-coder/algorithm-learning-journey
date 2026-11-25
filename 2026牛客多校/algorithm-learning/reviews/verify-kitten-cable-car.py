"""Verify submitted DFS/DP and templates against exact subset partition DP."""
import json
import random
import subprocess
import tempfile
from pathlib import Path

root = Path(__file__).resolve().parents[1]
compiler = "D:/mingw64/mingw64/bin/g++.exe"
sources = [root / "reviews/kitten-cable-car-submitted.cpp",
           root / "templates/dfs-bin-packing.cpp",
           root / "reviews/kitten-cable-car-dp-submitted.cpp",
           root / "templates/subset-bin-packing.cpp"]
executables = []
build = tempfile.TemporaryDirectory(prefix="kitten-verify-")
for source in sources:
    exe = Path(build.name) / (source.stem + ".exe")
    subprocess.run([compiler, "-std=c++17", "-O2", "-Wall", "-Wextra",
                    str(source), "-o", str(exe)], check=True, capture_output=True)
    executables.append(exe)

def oracle(weights, capacity):
    """Partition subsets into feasible cars; no last-car DP or recursive packing."""
    size = 1 << len(weights)
    sums = [0] * size
    best = [len(weights) + 1] * size
    best[0] = 0
    for mask in range(1, size):
        anchor = mask & -mask
        sums[mask] = sums[mask ^ anchor] + weights[anchor.bit_length() - 1]
        sub = mask
        while sub:
            if sub & anchor and sums[sub] <= capacity:
                best[mask] = min(best[mask], 1 + best[mask ^ sub])
            sub = (sub - 1) & mask
    return best[-1]

cases = [([1, 2, 1994, 12, 29], 1996, 2),
         ([1], 1, 1), ([100000000], 100000000, 1),
         ([6, 4], 10, 1), ([6, 5, 4], 10, 2),
         ([2, 3, 4, 5], 10, 2),
         ([1] * 18, 18, 1), ([1] * 18, 1, 18),
         ([100000000] * 18, 100000000, 18)]
rng = random.Random(20261022)
for _ in range(60):
    count = rng.randint(1, 9)
    capacity = rng.randint(1, 30)
    weights = [rng.randint(1, capacity) for _ in range(count)]
    cases.append((weights, capacity, oracle(weights, capacity)))

for number, (weights, capacity, expected) in enumerate(cases):
    data = f"{len(weights)} {capacity}\n" + "\n".join(map(str, weights)) + "\n"
    for exe in executables:
        result = subprocess.run([str(exe)], input=data, text=True,
                                capture_output=True, timeout=5, check=True)
        actual = int(result.stdout.strip())
        if actual != expected:
            raise AssertionError((number, exe.name, weights, capacity, expected, actual))

print(json.dumps({"status": "local_passed", "date": "2026-10-22",
                  "compiler": "g++ -std=c++17 -O2 -Wall -Wextra",
                  "sources": [str(p.relative_to(root)) for p in sources],
                  "case_count_per_implementation": len(cases),
                  "random_cases": 60, "random_seed": 20261022,
                  "oracle": "exact feasible-subset partition DP on n<=9",
                  "boundaries": "sample, exact fit, one cat, n=18, w=1e8",
                  "online_verdict": None,
                  "limitations": "not an exhaustive proof or worst-case runtime guarantee"},
                 ensure_ascii=False, indent=2))
build.cleanup()
