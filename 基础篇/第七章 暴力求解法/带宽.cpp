#include<bits/stdc++.h>
#define L
using namespace std;

int main(){
#ifdef L
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	string line;
	while(getline(cin,line)){
		if(line == "#") break;
		vector<bool> ext(26,false);		//判断26个字母是否存在
		vector<vector<bool>> adj(26,vector<bool>(26,false));	//邻接矩阵
		vector<int> a;
		for(int i = 0; i < (int)line.length(); ++i){
			int j = i;
			while(j < (int)line.length() && line[j] != ';'){
				j++;
			}
			for(int k = i + 2; k < j; k++){
				int u = line[k]-'A';
				int v = line[i]-'A';
				ext[u] = true;
				ext[v] = true;
				adj[u][v] = true;
				adj[v][u] = true;
			}
			i = j;
		}
		vector<int> nodes;
		for(int i = 0; i < 26; ++i){
			if(ext[i]) nodes.push_back(i);
		}
		vector<int> best_order;		//存答案
		int minBand = 10;			//存答案
		sort(nodes.begin(),nodes.end());
		do{
			int maxBand = 0;
			//nodes 存的是 字母编号：A=0, B=1, C=2, D=3
			//i 是 排列里的位置（第几位）
			//pos[ 字母编号 ] = 位置
			int pos[26] = {0};
			for(int i = 0; i < (int)nodes.size(); ++i){
				pos[ nodes[i] ] = i;
			}
			for(int i = 0; i < 26; ++i){
				for(int j = i+1; j < 26; ++j){	//遍历二维数组,i，j代表字母编号
					if(adj[i][j]){
						maxBand = max(maxBand,abs(pos[i]-pos[j]));
					} 
				}
			}
			if(minBand > maxBand || (minBand == maxBand && nodes < best_order)){
				minBand = maxBand;
				best_order = nodes;
			}
		}while(next_permutation(nodes.begin(),nodes.end()));
		for(int i = 0; i < (int)best_order.size(); ++i){
			cout << (char)(best_order[i] + 'A') << " ";
		}
		cout << "-> " << minBand << "\n";
	}

	return 0;
}
