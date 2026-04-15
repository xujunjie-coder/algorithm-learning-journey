#include<bits/stdc++.h>
#define L
using namespace std;
// 判断单个目标序列是否能通过栈重组得到
bool isPossible(int N, const vector<int>& target) {
	stack<int> station; // 模拟车站栈
	int current = 1; // 待压入栈的车厢编号（1~N）
	
	for (int num : target) {
		// 把当前编号及之前的车厢压入栈，直到栈顶为目标元素
		while (current <= N && (station.empty() || station.top() != num)) {
			station.push(current++);
		}
		// 若栈顶不是目标元素，说明无法匹配
		if (station.top() != num) {
			return false;
		}
		// 弹出栈顶元素（匹配成功）
		station.pop();
	}
	// 所有目标元素都匹配完成，栈为空则合法
	return station.empty();
}

// 读取一行输入并解析为目标序列（处理空格分隔的N个整数）
vector<int> readTarget(int N) {
	vector<int> target;
	string line;
	getline(cin, line);
	istringstream iss(line);
	int num;
	while (iss >> num) {
		target.push_back(num);
	}
	// 确保读取到N个元素（题目保证输入是1~N的排列）
	return target;
}
int main(){
#ifdef L
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	int N;
	bool firstBlock = true; // 标记是否是第一组数据（控制空行输出）
	
	// 外层循环：处理每组数据（N=0时结束）
	while (cin >> N && N != 0) {
		// 每组数据输出后要空一行，第一组前不输出空行
		if (!firstBlock) {
			cout << endl;
		}
		firstBlock = false;
		
		cin.ignore(); // 忽略N后的换行符，避免影响getline读取
		
		// 内层循环：处理当前组的多个目标序列（读到0时结束当前组）
		while (true) {
			vector<int> target = readTarget(N);
			// 判断是否是当前组的终止符（单独的0）
			if (target.size() == 1 && target[0] == 0) {
				break;
			}
			// 判断并输出结果（题目要求Yes/No首字母大写）
			if (isPossible(N, target)) {
				cout << "Yes" << endl;
			} else {
				cout << "No" << endl;
			}
		}
	}
	
	return 0;
}
