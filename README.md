![Algorithm Learning Journey](.github/assets/portfolio-banner.svg)

# 许俊杰 · 算法与数据结构

> 以 C++ 进行算法训练，围绕题意建模、状态设计、复杂度分析和边界调试积累可复查的实现与解题记录。

**C++ / STL · 二分 · 前缀和与差分 · 搜索与回溯 · 分治 · 动态规划 · 图论**

本仓库汇总《算法竞赛入门经典》《算法竞赛进阶指南》及牛客、蓝桥杯等训练内容。可从下方能力索引查看代表代码，再通过题目复盘了解推导与调试过程。

## 算法能力速览

下表列出已有代码或复盘支撑的实践方向；具体完成方式与验证情况见代表题记录。

| 方向 | 已实践的算法与问题 | 代表实现 / 记录 |
| --- | --- | --- |
| C++ 与基础数据结构 | 使用数组、vector、栈、队列、优先队列；栈模拟、邻接表建图 | [栈与队列练习](%E5%9F%BA%E7%A1%80%E7%AF%87/%E7%AC%AC%E5%85%AD%E7%AB%A0%20%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E5%9F%BA%E7%A1%80/) · [链表与邻接表](%E7%AE%97%E6%B3%95%E8%BF%9B%E9%98%B6/0x10%20%E5%9F%BA%E6%9C%AC%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/0x13%20%E9%93%BE%E8%A1%A8%E4%B8%8E%E9%82%BB%E6%8E%A5%E8%A1%A8/) |
| 枚举与递归 | 子集、排列、组合枚举；递归边界与选择恢复 | [组合枚举](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/templates/recursive-combination-enumeration.cpp) · [排列枚举](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/templates/recursive-permutation-enumeration.cpp) |
| 前缀和与差分 | 区间统计、区间修改转端点变化、差分正负量统计 | [IncDec Sequence](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/problems/incdec-sequence.md) · [知识整理](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/knowledge/%E5%9F%BA%E6%9C%AC%E7%AE%97%E6%B3%95/%E5%89%8D%E7%BC%80%E5%92%8C%E4%B8%8E%E5%B7%AE%E5%88%86.md) |
| 二分答案 | 单调性判断、可行性检查；实数二分与前缀和判定 | [Best Cow Fences](%E7%AE%97%E6%B3%95%E8%BF%9B%E9%98%B6/0x00%20%E5%9F%BA%E6%9C%AC%E7%AE%97%E6%B3%95/0x04%20%E4%BA%8C%E5%88%86/Best%20Cow%20Fences.cpp) · [二分模板](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/templates/binary-search-answer.cpp) |
| 排序与分治 | 快速排序、归并统计逆序对、分治求最大子段和 | [逆序对](%E7%AE%97%E6%B3%95%E8%BF%9B%E9%98%B6/0x00%20%E5%9F%BA%E6%9C%AC%E7%AE%97%E6%B3%95/0x05%20%E6%8E%92%E5%BA%8F/%E3%80%90%E4%BE%8B%E9%A2%98%E3%80%91Ultra-QuickSort.cpp) · [分治练习](%E7%AB%9E%E8%B5%9B%E7%AF%87/%E7%AC%AC%E5%85%AB%E7%AB%A0%20%E9%AB%98%E6%95%88%E7%AE%97%E6%B3%95%E8%AE%BE%E8%AE%A1/) |
| 贪心与中位数 | 绝对距离和最小化；环形均分转前缀盈亏与中位数 | [仓库选址](%E7%AE%97%E6%B3%95%E8%BF%9B%E9%98%B6/0x00%20%E5%9F%BA%E6%9C%AC%E7%AE%97%E6%B3%95/0x05%20%E6%8E%92%E5%BA%8F/%E3%80%90%E4%BE%8B%E9%A2%98%E3%80%91%E4%BB%93%E5%BA%93%E9%80%89%E5%9D%80.cpp) · [七夕祭复盘](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/problems/tanabata.md) |
| DFS / BFS 与回溯 | 连通块、无权最短路、装箱搜索；搜索顺序与最优性剪枝 | [BFS 最短路](%E6%97%A5%E5%B8%B8%E5%88%B7%E9%A2%98/%E6%97%A0%E6%9D%83%E5%9B%BE%E7%9A%84%E6%9C%80%E7%9F%AD%E8%B7%AF%E5%BE%84%E3%80%90bfs%E3%80%91.cpp) · [木棒复盘](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/problems/sticks-min-original-length.md) |
| 动态规划 | LIS、LCS；集合状态设计与状压 DP；记忆化搜索计数 | [LIS](%E7%AB%9E%E8%B5%9B%E7%AF%87/%E7%AC%AC%E4%B9%9D%E7%AB%A0%20%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%E5%88%9D%E6%AD%A5/%E6%9C%80%E9%95%BF%E4%B8%8A%E5%8D%87%E5%AD%90%E5%BA%8F%E5%88%97LIS.cpp) · [LCS](%E7%AB%9E%E8%B5%9B%E7%AF%87/%E7%AC%AC%E4%B9%9D%E7%AB%A0%20%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%E5%88%9D%E6%AD%A5/%E6%9C%80%E9%95%BF%E5%85%AC%E5%85%B1%E5%AD%90%E5%BA%8F%E5%88%97LCS.cpp) · [小猫爬山](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/problems/kitten-cable-car.md) |
| 离散化与并查集 | 排序去重、二分映射、路径压缩；相等与不等关系判定 | [通过版代码](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/reviews/discrete-dsu-accepted.cpp) · [约束问题复盘](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/problems/local-discrete-dsu-constraints.md) |
| 字符串哈希 | 前缀哈希、子串哈希提取、正反串映射 | [哈希模板](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/templates/rolling-hash-string.cpp) · [回文问题复盘](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/problems/nowcoder-nc50987-palindrome.md) |
| 基础数论 | 欧几里得算法、质因数分解、模快速幂、分治等比数列求和 | [GCD](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/templates/gcd-euclidean.cpp) · [快速幂](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/templates/modular-fast-power.cpp) · [约数和复盘](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/problems/sum-divisors-power-mod-9901.md) |

## 代表题与解题过程

以下题目集中展示建模、方法比较和调试细节，适合作为代码阅读与技术交流入口。

| 代表题 | 核心思路与可讨论内容 | 代码与复盘 | 验证记录 |
| --- | --- | --- | --- |
| IncDec Sequence | 将区间加减转为差分端点变化；由正负差分总量推导操作下界与结果种数；检查 64 位溢出 | [代码](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/reviews/incdec-sequence-accepted.cpp) · [推导](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/problems/incdec-sequence.md) | 报告在线通过；复盘记录 39 组穷举对照与 3 组回归用例 |
| 七夕祭 | 行列分别建模；用前缀盈亏表示环上流量，再以中位数最小化代价 | [修正版](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/reviews/tanabata-corrected.cpp) · [复盘](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/problems/tanabata.md) | 修改后报告在线通过；源码按对话重建 |
| 小猫爬山 | 比较 DFS 装箱与状压 DP；设计“已选集合、车辆数、剩余容量”，合并较差状态 | [DFS](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/reviews/kitten-cable-car-submitted.cpp) · [DP](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/reviews/kitten-cable-car-dp-submitted.cpp) · [复盘](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/problems/kitten-cable-car.md) | 原版与模板各 69 组本地用例 |
| 木棒 | 枚举原木长度、回溯分组；分析排序、重复选择与失败分支剪枝的依据 | [代码](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/reviews/sticks-min-original-length-submitted.cpp) · [复盘](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/problems/sticks-min-original-length.md) | 引导修正后报告在线通过 |
| 离散化 + 并查集 | 将原值映射为节点编号；先合并等式再检查不等式；处理初始化与多组清理 | [代码](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/reviews/discrete-dsu-accepted.cpp) · [复盘](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/problems/local-discrete-dsu-constraints.md) | 引导修正后报告在线通过；另有本地对照 |
| 班级合照 | 由合法放置规则构造人数状态，用记忆化复用后缀方案数；比较递推 DP | [记忆化代码](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/reviews/young-tableaux-photo-submitted.cpp) · [复盘](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/problems/young-tableaux-photo.md) | 记忆化版报告在线通过；三种实现各 358 组本地对照 |

“报告在线通过”来自个人学习记录；本地对照与在线评测分别标注。部分题目在引导下完成，复盘保留完成方式、历史错误与后续复习点。

## 进阶拓展

| 正在巩固的内容 | 当前练习重点 | 阅读入口 |
| --- | --- | --- |
| Dijkstra 单源最短路 | 邻接矩阵与邻接表表示、小根堆取点、松弛与访问标记 | [邻接表 + 小根堆实现](%E7%AE%97%E6%B3%95%E8%BF%9B%E9%98%B6/0x60%20%E5%9B%BE%E8%AE%BA/%E5%8D%95%E6%BA%90%E6%9C%80%E7%9F%AD%E8%B7%AF-%E8%BF%AA%E6%9D%B0%E6%96%AF%E7%89%B9%E6%8B%89-2.cpp) · [知识卡](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/knowledge/%E5%9B%BE%E8%AE%BA/Dijkstra%E5%8D%95%E6%BA%90%E6%9C%80%E7%9F%AD%E8%B7%AF.md) |
| 动态候选维护 | 双向链表维护相邻关系，堆保存候选并过滤失效记录 | [相邻最小和合并](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/problems/niuke-2026-adjacent-min-sum-merge.md) |
| 组合计数 | 杨图、标准杨表、勾长公式与先约分后乘的计算方式 | [概念与推导](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/knowledge/%E7%BB%84%E5%90%88%E6%95%B0%E5%AD%A6/%E6%9D%A8%E5%9B%BE%E4%B8%8E%E5%8B%BE%E9%95%BF%E5%85%AC%E5%BC%8F.md) |

## 代码之外的积累

- **推导与复杂度**：记录状态含义、转移条件、正确性依据，以及时间和空间开销。
- **错误与边界**：保留初始化、下标、溢出、回溯恢复和多组数据残留等问题及修正。
- **方法对照**：对同一问题比较 DFS、DP 或数学解法，说明各自适用条件。
- **本地验证**：部分题目提供 Python 对照脚本与 JSON 结果，可沿记录复查测试范围。

集中入口：[题目复盘](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/problems/) · [可复用模板](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/templates/) · [知识卡片](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/knowledge/) · [验证与调试记录](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/reviews/)

## 按学习来源浏览

| 内容 | 目录 |
| --- | --- |
| 《算法竞赛入门经典》 | [基础篇](%E5%9F%BA%E7%A1%80%E7%AF%87/) · [竞赛篇](%E7%AB%9E%E8%B5%9B%E7%AF%87/) |
| 《算法竞赛进阶指南》章节代码 | [算法进阶](%E7%AE%97%E6%B3%95%E8%BF%9B%E9%98%B6/) |
| 知识卡片、题目复盘与模板 | [算法学习库](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/algorithm-learning/) |
| 牛客与蓝桥杯训练 | [2026 牛客多校](2026%E7%89%9B%E5%AE%A2%E5%A4%9A%E6%A0%A1/) · [牛客寒假训练营](%E7%89%9B%E5%AE%A2%E5%AF%92%E5%81%87%E8%AE%AD%E7%BB%83%E8%90%A5/) · [蓝桥杯](%E8%93%9D%E6%A1%A5%E6%9D%AF/) |
| 日常练习与笔记 | [日常刷题](%E6%97%A5%E5%B8%B8%E5%88%B7%E9%A2%98/) · [notes](notes/) |

## 运行方式

多数 C++ 源文件按题目独立编译，使用对应题目的标准输入：

```bash
g++ -std=c++17 -O2 solution.cpp -o solution
./solution
```

Windows 下可运行生成的 `solution.exe`。部分文件使用 `bits/stdc++.h`，建议使用 GCC / MinGW。历史目录保留练习稿和未完成版本，优先阅读上方代表题及其验证记录。

## 许可证

代码按现有 [MIT License](LICENSE) 使用；教材题目与第三方材料的权利归原作者所有。
