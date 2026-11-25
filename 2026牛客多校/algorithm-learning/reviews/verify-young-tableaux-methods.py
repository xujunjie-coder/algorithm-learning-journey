"""编译三种实现，与独立的整数分拆维数乘积公式对照；不等同在线 AC。"""
import itertools
import json
import math
from pathlib import Path
import random
import shutil
import subprocess

ROOT = Path(__file__).resolve().parent
BUILD = ROOT / '.build'
BUILD.mkdir(exist_ok=True)

def dimension(shape):
    # f^lambda = N! * prod_{i<j}(l_i-l_j) / prod_i(l_i!), l_i=lambda_i+k-1-i
    k = len(shape)
    shifted = [v+k-1-i for i, v in enumerate(shape)]
    num = math.factorial(sum(shape))
    for i, j in itertools.combinations(range(k), 2):
        num *= shifted[i] - shifted[j]
    den = math.prod(math.factorial(v) for v in shifted)
    assert num % den == 0
    return num // den

def partitions(total, ceiling, slots):
    if total == 0:
        yield ()
    elif slots:
        for first in range(min(total, ceiling), 0, -1):
            for tail in partitions(total-first, first, slots-1):
                yield (first,) + tail

samples = [(30,), (1,1,1,1,1), (3,2,1), (5,3,3,1), (6,5,4,3,2), (15,15)]
expected_samples = [1, 1, 16, 4158, 141892608, 9694845]
assert [dimension(s) for s in samples] == expected_samples
small = [s for total in range(1, 13) for s in partitions(total, total, 5)]
rng = random.Random(20261023)
large = [s for total in range(13, 31) for s in partitions(total, total, 5)
         if dimension(s) <= 2**32-1]
random_cases = rng.sample(large, min(150, len(large)))
# 明确检查排数缩减和扩展，防止尾部容量残留。
switches = [(1,1,1,1,1), (2,), (15,15), (1,), (6,5,4,3,2), (2,1)]
cases = samples + small + random_cases + switches
data = ''.join(f'{len(s)}\n'+' '.join(map(str,s))+'\n' for s in cases)+'0\n'
expected = [dimension(s) for s in cases]
compiler = shutil.which('g++')
assert compiler, '需要 g++'
results = {}
for method, source in {
    'memo_user_ac': 'young-tableaux-photo-submitted.cpp',
    'dp_reference': 'young-tableaux-dp-reference.cpp',
    'hook_reference': 'young-tableaux-hook-reference.cpp',
}.items():
    exe = BUILD / f'young-tableaux-{method}.exe'
    subprocess.run([compiler, '-std=c++17', '-O2', str(ROOT/source), '-o', str(exe)],
                   check=True, capture_output=True, text=True)
    proc = subprocess.run([str(exe)], input=data, capture_output=True, text=True,
                          check=True, timeout=60)
    actual = [int(v) for v in proc.stdout.split()]
    assert actual == expected, f'{method} 对照失败'
    results[method] = {'compile': 'pass', 'passed': len(cases),
                       'source': source, 'online_verdict': 'user_reported_AC' if method == 'memo_user_ac' else None}
record = {'date': '2026-10-23', 'standard': 'C++17', 'seed': 20261023,
          'case_count': len(cases), 'sample_count': len(samples),
          'exhaustive_total_le_12': len(small), 'random_valid_cases': len(random_cases),
          'multi_case_switch_count': len(switches),
          'oracle': 'Python 大整数整数分拆维数乘积式；并核对题面六个样例',
          'status': 'passed', 'results': results,
          'note': 'DP 和勾长是助手参考实现，只登记本地验证，不登记在线 AC 或独立解题。'}
(ROOT/'young-tableaux-methods-verification.json').write_text(
    json.dumps(record, ensure_ascii=False, indent=2)+'\n', encoding='utf-8')
print(json.dumps(record, ensure_ascii=False))
