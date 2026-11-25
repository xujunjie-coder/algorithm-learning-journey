# 算法竞赛进阶指南学习库

本目录用于记录《算法竞赛进阶指南》题目复盘、可复用知识卡片和经过验证的代码模板。

- [学习进度](progress.md)
- [知识卡片](knowledge/)
- [正式模板](templates/)
- [题目复盘](problems/)

正式模板只收录已经验证正确的代码；调试中的实现保留在当前题目的复盘或工作流状态中。

本次完成：[班级合照复盘](problems/young-tableaux-photo.md)、[逐步推导记录](reviews/young-tableaux-learning.md)、[AC 原版](reviews/young-tableaux-photo-submitted.cpp)、[记忆化搜索计数卡](knowledge/动态规划/记忆化搜索计数.md)及[五排前缀计数模板](templates/row-prefix-memo-count.cpp)。用户报告 AC，引导完成；理解缺口逐项记录，初始化边界优先复习。

教学偏好（2026-10-23）：先从小例子开始，一次推进一个问题，让学习者尝试后再纠正，重视思维培养，不提前揭示整题关键或完整答案。

班级合照追加方法：已在题目复盘中补齐递推 DP 与勾长公式，新增[杨图、标准杨表与勾长公式](knowledge/组合数学/杨图与勾长公式.md)卡片，以及 [DP 模板](templates/row-prefix-dp-count.cpp)、[勾长约分模板](templates/young-tableaux-hook-count.cpp)。三种实现各通过 358 组[本地对照](reviews/young-tableaux-methods-verification.json)；仅原 DFS 有用户报告在线 AC。

学习约定（2026-10-16 用户明确授权）：这批算法题及本对话后续算法学习启用学习管理，直接整理题目与复用知识，不重复询问是否启用。调试优先保留用户原代码结构；遇到可复用实现时，验证后再收录正式模板。未提供的新题不预先创建题目记录，未收到 AC 不标记独立解题。

本次数论模板：

- [手写最大公约数](templates/gcd-euclidean.cpp)：`gcdll(a,b)`。
- [分数约分](templates/fraction-reduction.cpp)：`huajian(zi,mu)`，统一正分母，零化为 `0/1`；依赖相邻 gcd 模板。
- [整数根式化简](templates/square-root-simplification.cpp)：`simplifySqrt(n)`，返回根号外系数与根号内剩余数。
- [本地验证记录](reviews/number-theory-verification.json)。

当前已归档题目：

- [木棒：DFS 错误、剪枝证明与递归理解复盘（用户报告 AC）](problems/sticks-min-original-length.md)
- [小猫爬山：DFS 写法、状压 DP 与个人错误复盘](problems/kitten-cable-car.md)
- [相邻最小和合并：动态维护候选对](problems/niuke-2026-adjacent-min-sum-merge.md)
- [NC50987 Palindrome](problems/nowcoder-nc50987-palindrome.md)
- [递归指数型枚举：子集枚举](problems/recursive-subset-enumeration.md)
- [递归组合型枚举：从 n 个数中选 m 个](problems/recursive-combination-enumeration.md)
- [递归排列型枚举：1..n 的全排列](problems/recursive-permutation-enumeration.md)
- [5×5 拉灯游戏：枚举第一行与逐行递推](problems/lights-out-5x5.md)
- [汉诺塔：递归式推导](problems/hanoi-recursion.md)
- [约数和取模：Sumdiv 9901](problems/sum-divisors-power-mod-9901.md)
- [一元二次方程较大根的精确输出](problems/quadratic-larger-root.md)
- [字符串哈希](knowledge/字符串/字符串哈希.md)
- [二分答案](knowledge/0x04-基本算法-二分/二分答案.md)
- [递归指数型枚举](knowledge/递归/递归指数型枚举.md)
- [枚举第一行与逐行递推](knowledge/递推/枚举第一行与逐行递推.md)
- [递归式推导](knowledge/递归/递归式推导.md)
- [质因数分解与约数和](knowledge/数论/质因数分解与约数和.md)
- [欧几里得算法（最大公约数）](knowledge/数论/欧几里得算法.md)
- [最简分数与符号规范](knowledge/数论/最简分数与符号规范.md)
- [整数根式化简](knowledge/数论/整数根式化简.md)
- [Dijkstra 单源最短路](knowledge/图论/Dijkstra单源最短路.md)
- [动态维护候选与懒删除堆](knowledge/数据结构/动态维护候选与懒删除堆.md)
- [回溯搜索与最优性剪枝](knowledge/搜索/回溯搜索与最优性剪枝.md)
- [状压装箱 DP](knowledge/动态规划/状压装箱DP.md)

小猫爬山相关资料：

- [用户本次 DFS 原版](reviews/kitten-cable-car-submitted.cpp)
- [DFS 装箱模板](templates/dfs-bin-packing.cpp)：保留剩余容量、1-based 编号与回溯写法，增强上界剪枝。
- [用户状压 DP 原版](reviews/kitten-cable-car-dp-submitted.cpp)
- [状压装箱 DP 模板](templates/subset-bin-packing.cpp)：沿用剩余容量语义，代码中标注旧错 1~7。
- [本地验证记录](reviews/kitten-cable-car-verification.json)：DFS、DP 原版及模板各 69 组用例，不等于在线 AC。

2026-10-28：[离散化＋并查集复盘](problems/local-discrete-dsu-constraints.md)、[带旧错标记模板](templates/discrete-dsu.cpp)、[离散化卡](knowledge/基本算法/离散化.md)、[并查集卡](knowledge/数据结构/并查集.md)。重点标记原值／下标／节点编号混淆、初始化边界、递归推进、按根合并和多组清理；本地验证见[结果](reviews/discrete-dsu-verification.json)，未收到明确在线 AC。

2026-10-28后续更新：用户补交修正版并明确报告 **AC**，已保存[AC代码](reviews/discrete-dsu-accepted.cpp)并更新[本题复盘](problems/local-discrete-dsu-constraints.md)。此前“未报告AC”描述属于补交前记录；当前结论为引导完成、用户报告AC。两卡仍为需要复习，计数不重复增加，原错误标记保留。

2026-10-30：已归档[七夕祭复盘](problems/tanabata.md)、[纠错前代码](reviews/tanabata-submitted.cpp)、[对话重建修正版](reviews/tanabata-corrected.cpp)及[环形均分知识卡](knowledge/基本算法/环形均分与前缀和中位数.md)。用户报告修改后 AC；重点记录 row 未初始化、both 漏加列代价、总答案 int 范围不足。

2026-11-11：[IncDec Sequence 复盘](problems/incdec-sequence.md)、[通过版重建源码](reviews/incdec-sequence-accepted.cpp)、[前缀和与差分知识卡](knowledge/基本算法/前缀和与差分.md)。

