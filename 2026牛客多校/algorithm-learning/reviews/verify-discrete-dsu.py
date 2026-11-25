from pathlib import Path
import subprocess, random, json

root = Path(__file__).resolve().parents[1]
review = root / 'reviews'
original = (review / 'discrete-dsu-submitted.cpp').read_text(encoding='utf-8')
corrected = original.replace('for(int i = 0; i < len; ++i)',
    '// 修正：get_id 返回 1..len，初始化必须覆盖同一区间。\n        for(int i = 1; i <= len; ++i)')
(review / 'discrete-dsu-corrected.cpp').write_text(corrected, encoding='utf-8')
rng = random.Random(20261028)
cases = [ [(1,1,0)], [(1,1,1)], [(30,100,1),(100,5000,1),(30,5000,0)],
          [(30,100,0)], [(30,100,1)], [(30,100,0)],
          [(1000000000,-1000000000,1),(1000000000,-1000000000,0)] ]
for _ in range(300):
    labels = rng.sample(range(-100000,100000), rng.randint(1,12))
    cases.append([(rng.choice(labels),rng.choice(labels),rng.randrange(2))
                  for _ in range(rng.randint(1,40))])

def oracle(edges):
    # 独立参照：等式建无向图，用 DFS 标连通分量，再检查不等式。
    graph = {}
    for x,y,e in edges:
        graph.setdefault(x,[]); graph.setdefault(y,[])
        if e: graph[x].append(y); graph[y].append(x)
    comp = {}
    for x in graph:
        if x in comp: continue
        comp[x] = x; stack = [x]
        while stack:
            u = stack.pop()
            for v in graph[u]:
                if v not in comp: comp[v] = x; stack.append(v)
    return 'NO' if any(not e and comp[x]==comp[y] for x,y,e in edges) else 'YES'

def run(source, group):
    exe = review / (source.stem + '.exe')
    subprocess.run(['g++','-std=c++17','-O2',str(source),'-o',str(exe)],check=True,capture_output=True)
    data = str(len(group))+'\n'+''.join(str(len(c))+'\n'+''.join(f'{x} {y} {e}\n' for x,y,e in c) for c in group)
    p = subprocess.run([str(exe)],input=data,text=True,capture_output=True,timeout=30,check=True)
    expected = [oracle(c) for c in group]
    assert p.stdout.split() == expected, source
    return {'source':str(source.relative_to(root)), 'passed':len(group)}

results = [run(review/'discrete-dsu-submitted.cpp',cases),
           run(review/'discrete-dsu-corrected.cpp',cases)]
# 压力用例用于增强模板，避免把短用例通过误当作原递归版的大规模安全保证。
chain = [(i,i+1,1) for i in range(1,100001)]+[(1,100001,0)]
distinct = [(2*i,2*i+1,0) for i in range(110000)]
results.append(run(root/'templates/discrete-dsu.cpp',cases+[chain,distinct]))
out = {'date':'2026-10-28','seed':20261028,'oracle':'equality graph + DFS components',
       'results':results,'online_verdict':None,'independent_solve':False,
       'note':'用户原版通过小规模对照不能证明初始化契约正确；漏初始化的末节点借用虚拟根0。增强模板另测长链及22万不同标签。'}
(review/'discrete-dsu-verification.json').write_text(json.dumps(out,ensure_ascii=False,indent=2),encoding='utf-8')
print(json.dumps(out,ensure_ascii=False,indent=2))
