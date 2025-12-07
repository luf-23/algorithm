#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string str;
	cin >> str;
	str = ' ' + str;
	stack<int>pos;
	int BOOL[200005] = {0};
	int d[200005] = {0};
	for (int i=1;i<str.length();i++){
		if (str[i]=='(') pos.push(i);
		else if (str[i]==')'&&!pos.empty()){
			d[pos.top()]++;
			d[i+1]--;
			pos.pop();
		}
	}
	for (int i=1;i<=str.length();i++) BOOL[i] = BOOL[i-1] + d[i];
	for (int i=1;i<str.length();i++){
		if (!BOOL[i]) cout << str[i];
	}
	return 0;
}
