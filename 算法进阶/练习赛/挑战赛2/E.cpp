#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define Item tuple<ll, int, int> // (-sum, -leftId, -rightId)

int const N = 2e5+5;
int tot,head,tail;
int T;
int n;
int a[N];
struct Node{
    ll val;
    int pre;
    int nxt;
    bool flag;  //默认都是活得
}node[N];

void init(){
    tot = 2;
    head = 1, tail = 2;
    node[head] = Node{0, 0, tail, false};
    node[tail] = Node{0, head, 0, false};
}
// 在 p 后插入新节点，并返回新节点编号
int insert(int p,ll val){
    int q = ++tot;
    node[q].val = val;
    node[node[p].nxt].pre = q;
    node[q].nxt = node[p].nxt;
    node[p].nxt = q;
    node[q].pre = p;
    node[q].flag = 1;   //默认活着'
    return q;
}

void remove(int p){
    node[node[p].nxt].pre = node[p].pre;
    node[node[p].pre].nxt = node[p].nxt;
    node[p].flag = 0;   //标记为死亡
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while(T--){
        init();
        cin >> n;
        int last = head;
        for(int i = 0; i < n; ++i){
            int val;cin >> val;
            last = insert(last,val);
        }
        priority_queue<Item> pq;
        //不是哨兵、两个节点都还活着、现在仍然相邻，才把候选放进堆里   
        auto pushpq = [&](int l,int r){
            if(l == head || r == tail) return;
            if(!node[l].flag || !node[r].flag) return;
            if(node[l].nxt != r || node[r].pre != l) return;
            // 默认大根堆：取相反数后，实际 sum 最小的候选优先；
            // sum 相同，-l 较大的候选优先，也就是 l 最小的候选优先。
            pq.push(make_tuple(-(node[l].val + node[r].val),-l,-r));
        };        
        
        //初始把所有相邻的都加入堆
        for(int l = node[head].nxt; l != tail; l = node[l].nxt){
            if(node[l].nxt != tail) pushpq(l,node[l].nxt);
        }

        ll ans = 0;
        int remain = n;
        while(remain > 1){
            Item cur = pq.top();
            pq.pop();

            ll summ = get<0>(cur);
            int left = get<1>(cur);
            int right = get<2>(cur);
            
            ll sum = -summ;
            int l = -left;
            int r = -right;

            if(l == head || r == tail) continue;
            if(!node[l].flag || !node[r].flag) continue;
            if(node[l].nxt != r || node[r].pre != l) continue;
            if (node[l].val + node[r].val != sum) continue;     //新加判断是区分原堆和新更新的l与l.pre的堆

            ans += sum;
            node[l].val = sum;

            node[r].flag = 0;
            node[node[r].nxt].pre = l;
            node[l].nxt = node[r].nxt;

            //少更新了一个l和l.pre他俩的sum也会因为l.val改变而改变
            pushpq(node[l].pre,l);
            pushpq(l,node[r].nxt);

            remain--;
        }
         cout << ans << "\n";       
            
        
    }
    

    return 0;
}