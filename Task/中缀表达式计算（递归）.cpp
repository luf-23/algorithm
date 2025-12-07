#include <bits/stdc++.h>
#define int long long
using namespace std;
string str;
int number(int l,int r){
	int ans = 0;
	for (int i=l;i<=r;i++) ans = ans*10 + str[i]-'0';
	return ans;
}
int multiply(int a,int b){
	int ans = 1;
	int base = a;
	while (b){
		if (b&1) ans *= base;
		base *= base;
		b >>= 1;
	}
	return ans;
}
int calc(int l,int r){
	int pos1,pos2,pos3;
	pos1 = pos2 = pos3 = -1;
	int cnt = 0;
	for (int i=l;i<=r;i++){
		if ((str[i]=='+'||str[i]=='-')&&cnt==0) pos1 = i;
		else if ((str[i]=='*'||str[i]=='/')&&cnt==0) pos2 = i;
		else if (str[i]=='^'&&cnt==0) pos3 = i;
		else if (str[i]=='(') cnt++;
		else if (str[i]==')') cnt--;
	}
	if (pos1==-1&&pos2==-1&&pos3==-1){
		if (cnt>0&&str[l]=='(') return calc(l+1,r);
		else if (cnt<0&&str[r]==')') return calc(l,r-1);
		else if (cnt==0&&str[l]=='('&&str[r]==')') return calc(l+1,r-1);
		else return number(l,r);
	}
	if (pos1!=-1){
		if (str[pos1]=='+') return calc(l,pos1-1) + calc(pos1+1,r);
		else return calc(l,pos1-1) - calc(pos1+1,r);
	}else if (pos2!=-1){
		if (str[pos2]=='*') return calc(l,pos2-1) * calc(pos2+1,r);
		else return calc(l,pos2-1) / calc(pos2+1,r);
	}else if (pos3!=-1){
		return multiply(calc(l,pos3-1),calc(pos3+1,r));
	}
	return 0;
}
signed main(){
	cin >> str;
	int ans = calc(0,str.length()-1);
	cout << ans;
	return 0;
}

