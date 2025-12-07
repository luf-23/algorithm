#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
int p1 = 131;
int p2 = 29;
int mod2 = 1e9 + 7;
int mod = 1e9 + 9;
int pre[100005];
int pre2[100005];
int bk[100005];
int bk2[100005];
int pp1[100005];
int pp2[100005];
int q_pre(int bg,int ed){
	return (pre[ed] + mod2 - pre[bg-1]*pp1[ed-bg+1]%mod2)%mod2;
}
int q_bk(int bg,int ed){
	return (bk[ed] + mod2 - bk[bg+1]*pp1[bg-ed+1]%mod2)%mod2;
}
int q_pre2(int bg,int ed){
	return (pre2[ed] + mod - pre2[bg-1]*pp2[ed-bg+1]%mod)%mod;
}
int q_bk2(int bg,int ed){
	return (bk2[ed] + mod - (bk2[bg+1]*pp2[bg-ed+1])%mod)%mod;
}
signed main(){
	string str;
	cin >> str;
	str = ' ' + str;
	int len = str.length()-1;
	int p,q;
	int f = 1;
	for (p=1,q=len;p<=len&&q>=1;p++,q--){
		if (str[p]!=str[q]){
			f = 0;
			break;
		}
	}
	if (f){
		cout << 1 << ' ' << len;
		return 0;
	}else{
		str = str.substr(p,q-p+1);
		str = ' ' + str;
		len = str.length()-1;
	}
	for (int i=1;i<=len;i++){
		pre[i] = (pre[i-1]*p1 + str[i]-'0')%mod2;
		pre2[i] = (pre2[i-1]*p2 + str[i]-'0')%mod;
	}
	for (int i=len;i>=1;i--){
		bk[i] = (bk[i+1]*p1 + str[i]-'0')%mod2;
		bk2[i] = (bk2[i+1]*p2 + str[i]-'0')%mod;
	}
	pp1[0] = 1;
	pp2[0] = 1;
	for (int i=1;i<=100005;i++){
		pp1[i] = pp1[i-1]*p1%mod2;
		pp2[i] = pp2[i-1]*p2%mod;
	}
	//ABA型
	for (int i=1;i<=len-1;i++){
		int ans1,ans2,ans3,ans4;
		ans1 = q_pre(1,i);
		ans2 = q_pre(len-i+1,len);
		ans3 = q_pre2(1,i);
		ans4 = q_pre2(len-i+1,len);
		if (ans1==ans2&&ans3==ans4&&q_pre(i+1,len-i)==q_bk(len-i,i+1)){
			cout << p << ' ' << i+p-1;
			return 0;
		}
	}
	//AAB型
	for (int i=1;2*i<=len;i++){
		int ans1,ans2,ans3,ans4;
		ans1 = q_pre(1,i);
		ans2 = q_pre(i+1,2*i);
		ans3 = q_pre2(1,i);
		ans4 = q_pre2(i+1,2*i);
		if (ans1==ans2&&ans3==ans4&&q_pre(2*i+1,len)==q_bk(len,2*i+1)){
			cout << i+p << ' ' << len+p-1;
			return 0;
		}
	}
	//BAA型
	for (int i=len;2*i>=2+len;i--){
		int ans1,ans2,ans3,ans4;
		ans1 = bk[i];
		ans2 = q_bk(i-1,2*i-len-1);
		ans3 = bk2[i];
		ans4 = q_bk2(i-1,2*i-len-1);
		if (ans1==ans2&&ans3==ans4&&q_pre(1,2*i-len-2)==q_bk(2*i-len-2,1)){
			cout << p << ' ' << p+i-2;
			return 0;
		}
	}
	cout << "-1 -1";
	return 0;
}
