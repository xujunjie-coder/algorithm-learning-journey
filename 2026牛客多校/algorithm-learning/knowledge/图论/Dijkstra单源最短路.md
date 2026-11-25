---
name: Dijkstra 单源最短路
chapter: 图论（章节待确认）
status: 初次接触
encounter_count: 0
solved_count: 0
template_used_count: 0
problem_ids: []
last_updated: 2026-10-09
---

# Dijkstra 单源最短路

## 解决的问题

给定一个带权图和源点 `s`，求 `s` 到其他所有点的最短距离。适用于边权非负的有向图或无向图。

## 核心思路

维护 `dist[v]`，表示目前已知的从源点到 `v` 的最短路长度。每次选择尚未确定、`dist` 最小的点 `u`，把它的距离确定下来，再尝试通过 `u` 松弛邻边：

```text
如果 dist[v] > dist[u] + w(u,v)，就令 dist[v] = dist[u] + w(u,v)
```

非负边权保证：当 `u` 成为当前距离最小的未确定点时，任何其他尚未确定的点都不可能先绕一段路再以更短距离到达 `u`。因此此时 `dist[u]` 已经是最终答案。若存在负边，这个结论不成立。

## 优先队列实现

用小根堆快速找到当前距离最小的候选点。距离更新后把新值再次入堆；旧值不会删除，弹出时若它已经过期就跳过。

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<pair<int, ll>>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w}); // 有向边；无向图再加 graph[v].push_back({u, w})
    }

    const ll INF = (1LL << 62);
    vector<ll> dist(n + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) continue; // 堆中的过期记录

        for (auto [v, w] : graph[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int v = 1; v <= n; ++v) {
        if (dist[v] == INF) cout << "INF";
        else cout << dist[v];
        cout << (v == n ? '\\n' : ' ');
    }
}
```

## 邻接矩阵实现

用户练习代码采用邻接矩阵 `a[u][v]` 存边权，每轮扫描所有点找未确定点中的最小距离，再扫描所有点尝试松弛。每轮 `O(n)`，共 `n` 轮，时间复杂度为 `O(n^2)`，空间复杂度为 `O(n^2)`，适合点数较少或图较稠密的场景。

- 初始化 `a[u][v] = INF` 表示没有边，`a[u][u] = 0` 表示到自身距离为 0。
- 多条 `u -> v` 边只保留最小边权。
- `v[x]` 表示点 `x` 的最短距离已经确定。
- 每轮先找 `!v[x]` 中 `d[x]` 最小的点，再用 `a[x][y]` 松弛所有 `y`。
- 有向图只存 `a[x][y]`；无向图还要存 `a[y][x]`。

练习代码只适用于非负边权，并假设距离和都能装入 `int`。若输入范围较大，应改用 `long long`；若最小未确定距离仍为 `INF`，可提前结束，避免处理不可达点。不可达点打印时应按题目要求输出，而不是直接把 `INF` 当成答案。

## 小根堆的两种写法

C++ 默认 `priority_queue<pair<T, int>>` 是大根堆。书上的写法把距离取相反数后入堆：`{ -dist, vertex }`。实际距离越小，其相反数越大，因此大根堆会先弹出真实距离最小的状态。初始状态 `{0, source}` 不受影响。

较直观的现代 C++ 写法是 `priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>>`，直接存 `{dist, vertex}`，由 `greater` 让较小 pair 位于堆顶。两种方法复杂度相同；`pair` 距离相同时会按顶点编号打破平局，具体先后不同但不影响最短距离。

书上用 `v[x]` 跳过已确定点，因此旧距离记录不必与当前 `d[x]` 显式比较。严格松弛且边权非负时，点第一次以最小距离出堆即可确定；之后该点的重复记录出堆会被 `v[x]` 跳过。

## 正确性不变量

- `dist[v]` 始终是某条已发现路径的长度，因此不会小于真实最短距离。
- 每次从堆中取出的有效最小值对应一个已确定的点；非负边权保证其距离不会再被改小。
- 松弛边 `u -> v` 后，`dist[v]` 仍对应一条实际可走的路径。

## 复杂度

邻接表加二叉堆的复杂度为 `O((n + m) log n)`，空间复杂度为 `O(n + m)`。

## 易错点

- 只能用于所有边权非负的图；有负边时考虑 Bellman-Ford 或 SPFA（需注意最坏复杂度）。
- 判断 `d != dist[u]` 后再扩展邻边，避免处理堆中的旧距离。
- 距离和边权可能很大时使用 `long long`，并选足够大的 `INF`。
- 不可达点保持 `INF`，输出时按题目要求处理。
- 输入若是无向图，每条边要存两个方向；有向图只存输入方向。

## 记忆方式

“拿出当前最近点、确定它、用它更新邻居”。关键条件是边权非负。
