#include <bits/stdc++.h>
#define int long long
using namespace std;
string str;
#define type double
int ff[100];
type number(int l,int r){
	type ans = 0;
	int pos = r;
	int pre,bk;
	pre = bk = 0;
	int f = 0;
	for (int i=l;i<=r;i++){
		if (str[i]!='.'){
			if (!f) pre = pre*10 + str[i]-'0';
			else bk = bk*10 + str[i]-'0';
		}else{
			f = 1;
			pos = i;
		}
	}
	ans = pre + bk*1.0/ff[r-pos];
	return ans;
}
type multiply(type a,int b){
	type ans = 1;
	type base = a;
	while (b){
		if (b&1) ans *= base;
		base *= base;
		b >>= 1;
	}
	return ans;
}
type calc(int l,int r){
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
	ff[0] = 1;
	for (int i=1;i<=15;i++) ff[i] = ff[i-1]*10;
	cin >> str;
	type ans = calc(0,str.length()-1);
	cout << fixed << setprecision(8) << ans;
	return 0;
}

