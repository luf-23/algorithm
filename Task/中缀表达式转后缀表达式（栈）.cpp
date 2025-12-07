#include <bits/stdc++.h>
#define int long long
using namespace std;
stack<int>num;
stack<char>op;
string str;
vector<string>ans;
int ksm(int a,int b){
	int ans = 1;
	int base = a;
	while (b){
		if (b&1) ans *= base;
		b >>= 1;
		base *= base;
	}
	return ans;
}
int pt(char t){
	if (t=='(') return 1;
	if (t=='+'||t=='-') return 2;
	if (t=='*'||t=='/') return 3;
	if (t=='^') return 4;
	if (t==')') return 5;
}
int calc(int x,int y,int t){
	int ans = x;
	if (t=='+') ans += y;
	if (t=='-') ans -= y;
	if (t=='*') ans *= y;
	if (t=='/') ans /= y;
	if (t=='^') ans = ksm(ans,y); 
	return ans;
}
void operate(char t){
	int y = num.top();
	num.pop();
	int x = num.top();
	num.pop();
	num.push(calc(x,y,t));
}
//括号多余情况暂未处理
signed main(){
	cin >> str;
	for (int i=0;i<str.length();i++){
		if (isdigit(str[i])){
			int x = 0;
			int j = i;
			while (j<str.length()&&isdigit(str[j])){
				x = x*10 + str[j]-'0';
				j++;
			}
			num.push(x);
			ans.push_back(to_string(x));
			i = j - 1;
		}else{
			if (str[i]=='(') op.push(str[i]);
			else if (str[i]==')'){
				while (op.top()!='('){
					operate(op.top());
					string now = "";
					now += op.top();
					ans.push_back(now);
					op.pop();
				}
				op.pop();
			}else{
				while (!op.empty()&&pt(str[i])<=pt(op.top())){
					operate(op.top());
					string now = "";
					now += op.top();
					ans.push_back(now);
					op.pop();
				}
				op.push(str[i]);
			}
		}
	}
	while (!op.empty()){
		operate(op.top());
		string now = "";
		now += op.top();
		ans.push_back(now);
		op.pop();
	}
	for (int i=0;i<ans.size();i++){
		if (i==0) cout << ans[i];
		else cout << ' ' << ans[i];
	}
	return 0;
} 
