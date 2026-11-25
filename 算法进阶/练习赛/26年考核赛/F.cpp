 #include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

int const N = 105;
int n;
int ans[N];
int v[N];
vector<int> g[N]; //二维数组存图

int ask(int i,int j){
    if(i > j) swap(i,j);
    cout << "S " << i << " " << j << endl;
    int res;
    cin >> res;
    if(res == -1) exit(0);
    return res;
}

void solve(){
    //1.获取原排列的正确位置个数
    ask(1,2);
    int base = ask(1,2);


    //2.将排列转为无向图
    for(int i = 1; i <= n; ++i){
        for(int j = i+1; j <= n; ++j){
            int res = ask(i,j);
            if(res > base){
                g[i].push_back(j);
                g[j].push_back(i);
            }
            ask(i,j);   //复原排列
        }
    }
    //这里再存一遍是因为会有很多不同的环（与77行代码）
    int score = base;
    //3.遍历所有节点处理图里面的环
    for(int i = 1; i <= n; ++i){
        if(v[i]) continue;

        //情况一：自环说明就是在正确的位置上
        if(g[i].size() == 0){
            ans[i] = i;
            v[i] = 1;
        }
        //情况二：二元环，互为正确位置
        else if(g[i].size() == 1){
            ans[g[i][0]] = i;
            ans[i] =  g[i][0];
            v[i] = 1;
            v[g[i][0]] = 1;
        }
        //情况三：存在俩邻居的至少三元的环
        else{
            vector<int> cyc;    //用于记录这个环
            int pre = 0;        //前驱
            int cur = i;
            do{ 
               
                int nxt = g[cur][0];  //后继
                if(pre == nxt){       //如果前驱和后继一样就换一个
                    nxt = g[cur][1];
                }
                cyc.push_back(cur);
                v[cur] = 1;
                pre = cur;
                cur = nxt;
            }while(cur != i);

            //判断环的方向并填入ans数组
            int before = score;
            //这里询问的是小环里面的第一个和第二个
            ask(cyc[0],cyc[1]);
            score = ask(cyc[1],cyc[2]);
            int len = cyc.size();
            if(score > before){ //说明是顺时针
                for(int j = 0; j < len; ++j){
                    ans[cyc[j]] = cyc[(j+1)%len];
                }
            }else{
                for(int j = 0; j < len; ++j){
                    ans[cyc[j]] = cyc[(j-1+len)%len];
                }
            }
        }
    }
}

void print(){
    cout << "!";
    for(int i = 1; i <= n; ++i){
        cout << " " << ans[i];
    }
    cout << endl;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    /*
    只要是全排列就一定有环，并且每个节点最多只有一个前驱和最多一个后继
    */   
    cin >> n;
    solve();
    print();

    return 0;
}