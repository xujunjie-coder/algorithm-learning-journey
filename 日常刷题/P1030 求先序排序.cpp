#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define Lo
#define ll long long
#define ull unsigned long long
#define endl '\n'
/*
思路：
	1.在后序排序中找到root字符
	2.在中序排序中找到root下标，将后序和中序排序分成左右子树
	3.进入递归并返回root+左子树+右子树；
*/
string buildpre(string inorder, string postorder){
	if (inorder.empty()) return ""; 					// 细节1: 终止条件：空树，返回空串
	char root = postorder.back();
	int pos = inorder.find(root);
	
	string leftin = inorder.substr(0,pos);
	string rightin = inorder.substr(pos+1);				// 细节2：因为每次传进来的都是子数，所以不用写长度
	string leftpost = postorder.substr(0,pos);
	string rightpost = postorder.substr(pos,rightin.size());
	
	return string(1,root) + buildpre(leftin,leftpost) + buildpre(rightin,rightpost);	//细节3：因为这里root是char类型的，需要转为string
	//用了一个string的构造函数string(n,c),意思是由n个字符c组成的string，这样就会避免char+string引发类型错误
}

int main()
{
#ifdef Lo
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	string inorder,postorder;
	cin >> inorder >> postorder;
	string ans = buildpre(inorder,postorder);
	cout << ans;
	return 0;
}
