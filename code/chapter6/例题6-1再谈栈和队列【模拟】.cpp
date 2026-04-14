#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cctype>
#include <sstream>
#define L
using namespace std;

// 辅助函数：去掉字符串中的所有空格
string delSpace(const string& s) {
	string res;
	for (char c : s) if (!isspace(c)) res += c;
	return res;
}

// 辅助函数：忽略输入中的空白行（处理Uva的空行分隔）
string getLine() {
	string s;
	while (getline(cin, s) && s.empty());
	return s;
}

int main() {
#ifdef L
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif

	int T;
	cin >> T;
	while (T--) {
		// 初始化全局状态（每组用例重置）
		int var[26] = {0}; // 共享变量初始0
		bool locked = false;
		queue<int> ready, blocked;
		vector<vector<string>> progs;
		vector<int> pc; // pc[0]弃用，pc[1~n]为程序ID的指针
		
		// 读入7个整数：n, t1, t2, t3, t4, t5, q
		int n, t1, t2, t3, t4, t5, q;
		cin >> n >> t1 >> t2 >> t3 >> t4 >> t5 >> q;
		cin.ignore(); // 忽略换行符，避免和getline冲突
		
		// 读入n个程序的指令
		for (int i = 0; i < n; i++) {
			vector<string> prog;
			string s;
			while (true) {
				s = getLine();
				s = delSpace(s); // 去掉所有空格
				prog.push_back(s);
				if (s == "end") break; // 程序以end结尾
			}
			progs.push_back(prog);
		}
		
		// 初始化PC指针（pc[1~n]，初始0）、就绪队列（1~n入队）
		pc.resize(n + 1, 0);
		for (int i = 1; i <= n; i++) ready.push(i);
		
		// 核心：进程调度模拟
		while (!ready.empty()) {
			int id = ready.front(); // 取出就绪队首程序ID
			ready.pop();
			int remain = q; // 剩余时间片
			int idx = pc[id]; // 当前要执行的指令下标
			vector<string>& prog = progs[id - 1]; // 该程序的所有指令（id-1对应progs索引）
			bool isBlock = false; // 是否lock失败被阻塞
			
			while (remain > 0) {
				string s = prog[idx];
				int cost = 0; // 本次指令的执行时间
				if (s.find('=') != string::npos) { // 1. 赋值指令：a=4
					cost = t1;
					char ch = s[0]; // 变量名
					int num = stoi(s.substr(2)); // 数值（s[1]是=）
					var[ch - 'a'] = num;
				} else if (s.substr(0, 5) == "print") { // 2. 输出指令：printa
					cost = t2;
					char ch = s[5]; // 要打印的变量
					cout << id << ": " << var[ch - 'a'] << '\n';
				} else if (s == "lock") { // 3. lock指令
					cost = t3;
					if (locked) { // 已加锁，加入阻塞队列
						blocked.push(id);
						isBlock = true;
						break; // 剩余时间片作废，跳出执行
					} else { // 未加锁，加锁
						locked = true;
					}
				} else if (s == "unlock") { // 4. unlock指令
					cost = t4;
					locked = false;
					if (!blocked.empty()) { // 阻塞队首移到就绪队首
						int bid = blocked.front();
						blocked.pop();
						ready.push(bid); // 先push再处理后续，等价于队首
					}
				} else if (s == "end") { // 5. end指令，程序结束
					cost = t5;
					remain = 0; // 强制结束，不加入队列
					idx++; // PC后移，标记结束
					break;
				}
				
				// 执行完指令：消耗时间片，PC指针后移
				remain -= cost;
				idx++;
				pc[id] = idx; // 更新PC指针
			}
			
			// 处理执行后的程序状态
			if (!isBlock && prog[pc[id]-1] != "end") { // 未阻塞+未结束，加入就绪队尾
				ready.push(id);
			}
			pc[id] = idx; // 最终更新PC指针（lock失败时idx未变）
		}
		
		// 用例间空行：最后一个用例后无空行
		if (T) cout << '\n';
	}
	return 0;
}
