# 相邻最小和合并：动态维护候选对

## 来源与章节

- 来源：用户提供的题面截图；可确认是牛客多校目录中的题目，但具体场次、题号和 URL 未提供。
- 相关章节：数据结构（优先队列与动态维护候选，教材章节待确认）。
- 学习状态：本次从暴力模拟推导出堆优化；尚未提供代码或评测结果，不计为独立解出或 AC。
- 本地记录 ID：`local-adjacent-min-sum-merge`。

## 题意抽象

维护一列包裹。每一步选取当前所有相邻对中重量和最小的一对；若并列，选最靠左的一对。把这一对合并成重量之和，替换原位置，并把这个和计入总费用。重复到只剩一个包裹，求总费用。

## 数据范围与复杂度要求

- 测试数 `t <= 10^4`；单组 `n <= 2*10^5`，所有测试的 `n` 之和不超过 `2*10^5`。
- `1 <= a_i <= 10^5`。
- 朴素做法每次线性扫描找最小相邻和，共进行 `n-1` 次，单组为 `O(n^2)`；最大数据下约有 `2*10^10` 次候选检查，无法通过。
- 每个合并和不超过所有初始重量之和 `2*10^10`；最多 `n-1` 次累计后使用 `long long`。

## 涉及知识点

- 最小堆维护动态候选集合。
- 懒删除：堆不支持任意删除时，保留旧记录并在取出时检查是否过期。
- 双向链表（用数组模拟）支持常数时间删除节点并维护相邻关系。
- 用字典序键 `(相邻和, 左端原始下标)` 处理“最小和，若并列取最左”。

## 思路推导

1. 先按题意直接模拟。每轮重扫所有相邻对，正确但为 `O(n^2)`。
2. 观察一次合并只会改变被合并区间附近的相邻关系和重量。远处的相邻对既没有改变重量，也没有改变相邻关系，所以它们的候选和仍然有效。
3. 需要同时支持两件事：快速取出全局最小的候选对；合并后只更新常数个候选对。前者用最小堆，后者用双向链表和局部重插。
4. 堆键使用 `(sum, leftId, rightId)`。`leftId` 是节点最初的下标；节点只会被删除，不会交换顺序，存活节点的 ID 顺序仍与当前从左到右顺序一致。因此相同 `sum` 时较小 `leftId` 就是最靠左的一对。
5. 合并相邻节点 `l,r` 时，把新重量存回左节点 `l`，从链表删除右节点 `r`。新候选至多是 `(prev[l],l)` 和 `(l,next[r])`；将它们加入堆即可。
6. 优先队列不能方便地删除旧候选，因此采用懒删除。每次取堆顶时验证端点仍存活、仍相邻、记录的和仍等于当前重量和；不满足就丢弃，直到拿到有效候选。

## 核心不变量或正确性

- 当前链表按原始下标顺序恰好保存所有存活包裹；合并后左端节点保留、右端节点删除。
- 对每个当前相邻对，堆中都有一条对应的有效记录：初始时全部入堆；一次合并仅改变/删除局部相邻对，受影响的新相邻对会重新入堆，其余有效记录保持不变。
- 堆中还可能有过期记录，但它们在弹出时会被检查并丢弃。于是第一个通过检查的堆顶，必然是所有当前相邻对中键最小的一对。
- 键先比较重量和、再比较左下标，恰好实现题目的优先级和左侧并列规则。
- 取出的有效对与题目规则完全相同；合并后维护链表和局部候选，因此每一步都与朴素模拟一致。由归纳可知整个合并序列及总费用一致。

## 我的实现

学习者本次没有提交代码。下面的 C++17 实现由助手按题意写出，使用 `Node[]` 数组模拟双向链表、头尾哨兵、懒删除和相反数堆键；尚未编译或评测，因此仅作参考，不计为学习者独立实现，也不作为正式代码模板。

## 参考实现（助手提供，未编译/未评测）

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Item = tuple<ll, int, int>; // (-sum, -leftId, -rightId)

struct Node {
    ll val;
    int pre, nxt;
    bool flag; // true 表示节点仍在链表中
};

const int N = 2e5 + 5;
Node node[N];
int tot, head, tail;

void init() {
    tot = 2;
    head = 1;
    tail = 2;

    node[head] = {0, 0, tail, false};
    node[tail] = {0, head, 0, false};
}

int insert(int p, ll val) {
    int q = ++tot;
    int r = node[p].nxt;

    node[q].val = val;
    node[q].pre = p;
    node[q].nxt = r;
    node[q].flag = true;

    node[p].nxt = q;
    node[r].pre = q;
    return q;
}

void remove(int p) {
    int l = node[p].pre;
    int r = node[p].nxt;

    node[l].nxt = r;
    node[r].pre = l;
    node[p].flag = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        init();

        // 按顺序插到链表末尾。last 始终是最后一个真实节点。
        int last = head;
        for (int i = 0; i < n; ++i) {
            ll val;
            cin >> val;
            last = insert(last, val);
        }

        priority_queue<Item> pq;
        auto push = [&](int l, int r) {
            if (l == head || r == tail) return;
            if (!node[l].flag || !node[r].flag) return;
            if (node[l].nxt != r || node[r].pre != l) return;

            pq.emplace(-(node[l].val + node[r].val), -l, -r);
        };

        // 从链表中枚举所有初始相邻对。
        for (int l = node[head].nxt; node[l].nxt != tail; l = node[l].nxt) {
            push(l, node[l].nxt);
        }

        ll answer = 0;
        int remain = n;

        while (remain > 1) {
            auto [negSum, negL, negR] = pq.top();
            pq.pop();

            ll sum = -negSum;
            int l = -negL;
            int r = -negR;

            // 懒删除：丢弃已删除、不再相邻或重量和已变化的旧记录。
            if (!node[l].flag || !node[r].flag) continue;
            if (node[l].nxt != r || node[r].pre != l) continue;
            if (node[l].val + node[r].val != sum) continue;

            answer += sum;
            node[l].val = sum; // 新包裹留在左节点 l 的位置
            remove(r);         // 从链表中删除右节点 r
            --remain;

            // 删除后，l 的左右邻居就是新产生的候选对。
            push(node[l].pre, l);
            push(l, node[l].nxt);
        }

        cout << answer << '\n';
    }

    return 0;
}
```

链表使用哨兵 `head=1`、`tail=2`，真实节点由 `insert` 依次创建。合并时让左节点 `l` 保存新重量，再用 `remove(r)` 删除右节点。堆键为 `(-sum,-l,-r)`；默认大根堆先取最小的 `sum`，并在相同 `sum` 时优先取最小的 `l`。`r` 只负责最后的平局次序，过期记录会由有效性检查过滤。

伪代码：

```text
把所有初始相邻对 (a[i]+a[i+1], i, i+1) 放入最小堆
while 存活节点数 > 1:
    弹出 (sum, l, r)
    若 l/r 已删除、l 不再紧邻 r、或当前和不等于 sum：跳过
    answer += sum
    weight[l] = sum
    从链表删除 r，并令 l 接上 r 的后继
    若 l 有前驱 p：加入 (weight[p]+weight[l], p, l)
    若 l 有后继 q：加入 (weight[l]+weight[q], l, q)
```

## 时间与空间复杂度

- 初始入堆 `n-1` 个候选；每次合并至多再入堆两个候选，所以总记录数为 `O(n)`。
- 每条记录最多入堆、出堆一次，时间复杂度 `O(n log n)`，空间复杂度 `O(n)`。

## 错误、反例与修复

- 本次未提供错误实现，因此不记录个人代码错误。以下是实现时的易错点：
- 只按和排序会遗漏“相同和取最左”；必须将左下标作为第二排序键。例如 `[1,100,1]` 的两个候选和都是 `101`，应先合并左侧。
- 用数组每次删除元素会移动后缀，仍可能退化为 `O(n^2)`；改为数组模拟的双向链表。
- 权重更新后，旧堆项可能仍在堆中；必须懒删除检查有效性，不能直接使用堆顶。
- 累加答案使用 `long long`，不能只看单个 `a_i` 的上限来选 `int`。

## 可迁移经验

遇到“反复选当前最小/最大对象，局部合并后继续”的模拟题，可按以下顺序找优化：先写直接模拟并算复杂度；再问一次操作会改变多少候选；若只改常数个，就只更新这些候选；若每轮还要找全局极值，再用堆；若堆内元素会失效且不便删除，就用懒删除；若动态删除/拼接使数组移动太贵，就用链表或等价的索引结构。

本题目前是讲解推导，尚未验证独立实现。特别值得练习的是亲自实现“堆 + 链表 + 过期记录检查”，并用并列最小值样例核对左优先。

## 关联知识卡片与模板

- [动态维护候选与懒删除堆](../knowledge/数据结构/动态维护候选与懒删除堆.md)：本题首次接触；未独立解出；未使用正式代码模板。
- 正式代码模板：暂无。本题尚未有经过验证的代码，不收录模板。
