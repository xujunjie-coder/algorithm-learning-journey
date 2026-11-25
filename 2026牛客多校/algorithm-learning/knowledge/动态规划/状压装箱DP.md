---
name: 状压装箱 DP
chapter: 动态规划（在线归档章节待核对）
status: 能够理解
encounter_count: 1
solved_count: 0
template_used_count: 0
problem_ids:
  - kitten-cable-car
last_updated: 2026-10-22
---

# 状压装箱 DP

## 解决的问题

小集合物品的最少容器数。需要记录“哪些物品已选”，容量却大到不适合按容量开稠密数组。

## 识别信号

n 约 18~20，集合状态可枚举；每次新增一个未安排物品；状态数 2^n，转移选择最多 n 个。

## 前提与限制

物品不可拆，单件 <= 容量，容器相同。只保存二元最优答案需要支配性依据，不能任意从二维状态删掉一维。

## 核心思路与不变量

mask 第 j 位代表 0-based 物品 j。`dp[mask]={cars,remaining}` 保存车辆更少优先、相同时剩余更多优先的方案。车辆相同时剩余多能模拟剩余少；车辆更少时可先开空车获得不超过另一方案的车辆数和不少于它的剩余空间，所以较差状态可舍弃。

`dp[0]={1,w}`，其他 `{n+1,0}`。候选 nxt 是旧答案的副本，加入新猫后与目标状态比较。`mask|(1<<j)` 比原 mask 大，可升序遍历。

## 标准模板

用户已补交完整的正确 DP 实现，保留在 [DP 原版](../../reviews/kitten-cable-car-dp-submitted.cpp)。[正式 DP 模板](../../templates/subset-bin-packing.cpp)沿用该状态与转移，并在相关行标出旧错 1~7；验证结果见 [本地记录](../../reviews/kitten-cable-car-verification.json)。未报告在线 AC。

```cpp
auto nxt = dp[mask];
if (nxt.second >= c[j]) nxt.second -= c[j];
else { ++nxt.first; nxt.second = w - c[j]; }
int target = mask | (1 << j);
if (nxt.first < dp[target].first ||
    (nxt.first == dp[target].first && nxt.second > dp[target].second))
    dp[target] = nxt;
```

## 常见变体

若第二字段保存“已用载重”，车辆相同应取载重小的，可以直接利用 pair 的字典序 min；保存剩余空间则需相反方向的比较。二者不变量不能混写。

## 易错点

默认 {0,0} 不是不可达；等于容量也可放；旧剩余量减猫重而非每次 w-c[j]；候选形成后再比较，不能直接覆盖目标；相等是 ==；全选状态是 (1<<n)-1。`dp[mask][2]` 是两个字段，和枚举容量的 `dp[mask][load]` 不同。

## 复杂度

时间 O(n*2^n)、空间 O(2^n)，在写代码前就能由集合数和每状态选择数估算；n=18 大约 472 万次简单检查。实际时限仍需结合环境，不把数量估算视为在线评测结果。

上面空间是所需状态量。当前源码固定声明 `dp[1<<20]`，实际分配 O(2^N) 个 pair，常见约 8 MiB，而循环访问的是前 2^n 个状态。

## 关联题目

- [小猫爬山](../../problems/kitten-cable-car.md)：用户先想到 DP，逐步理解状态与转移；补交正确实现并本地验证。在引导下写代码，未报告独立 AC、未使用既有模板；同题补充解法不增加 encounter_count。

## 我的经验

用户最初的“数量、车辆、剩余空间”已有主要信息；需把数量改为身份集合。当前能跟随推导，但初始化、候选与目标及比较方向还需独立复写巩固。
