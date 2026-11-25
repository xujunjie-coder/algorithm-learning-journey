#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
int const SIZE = 1e8;
int tot;    //节点编号
int head,tail;
struct Node{
    int value;
    int pre;    //前驱的节点编号
    int nxt;    //后继的节点编号
} node[SIZE];

//链表初始化
int init(){
    tot = 2;
    head = 1, tail = 2;
    node[head].nxt = tail;
    node[tail].pre = head;
}

//再p节点后插入节点
int insert(int p,int val){  
    int q = ++tot;
    node[q].value = val;
    node[node[p].nxt].pre = q;
    node[q].nxt = node[p].nxt;
    node[p].nxt = q;
    node[q].pre = p;
}

//删除p节点
void remove(int p){
    node[node[p].nxt].pre = node[p].pre;
    node[node[p].pre].nxt = node[p].nxt;
}

//清空链表
void clear(){
    memset(node,0,sizeof node);
    head = tail = tot = 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}