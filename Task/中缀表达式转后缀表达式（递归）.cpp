#include <bits/stdc++.h>
#define int long long
using namespace std;
string str;
vector<string>ans;
int calc(int l,int r){
	int pos1,pos2,pos3;
	pos1 = pos2 = pos3 = -1;
	int cnt = 0;
	for (int i=l;i<=r;i++){
		if (str[i]=='(') cnt++;
		if (str[i]==')') cnt--;
		if ((str[i]=='+'||str[i]=='-')&&cnt==0) pos1 = i;
		if ((str[i]=='*'||str[i]=='/')&&cnt==0) pos2 = i;
		if (str[i]=='^'&&cnt==0) pos3 = i;
	}
	//处理括号多余的情况
	if (pos1==-1&&pos2==-1&&pos3==-1){
		if (cnt>0&&str[l]=='(') return calc(l+1,r);
		else if (cnt<0&&str[r]==')') return calc(l,r-1);
		else if (cnt==0&&str[l]=='('&&str[r]==')') return calc(l+1,r-1);
		else{
			int ret = 0;
			for (int i=l;i<=r;i++) ret = ret*10 + str[i]-'0';
			ans.push_back(to_string(ret));
			return ret;
		}
	}
	if (pos1!=-1){
		if (str[pos1]=='+'){
			int x = calc(l,pos1-1);
			int y = calc(pos1+1,r);
			string now = "";
			now += '+';
			ans.push_back(now);
			return x+y;
		}
		else{
			int x = calc(l,pos1-1);
			int y = calc(pos1+1,r);
			string now = "";
			now += '-';
			ans.push_back(now);
			return x-y;
		}
	}else if (pos2!=-1){
		if (str[pos2]=='*'){
			int x = calc(l,pos2-1);
			int y = calc(pos2+1,r);
			string now = "";
			now += '*';
			ans.push_back(now);
			return x*y;
		}
		else{
			int x = calc(l,pos2-1);
			int y = calc(pos2+1,r);
			string now = "";
			now += '/';
			ans.push_back(now);
			return x/y;
		}
	}else if (pos3!=-1){
		int x = calc(l,pos3-1);
		int y = calc(pos3+1,r);
		string now = "";
		now += '^';
		ans.push_back(now);
		return pow(x,y);
	}
	return 0;
}
signed main(){
	cin >> str;
	int result = calc(0,str.length()-1);
	for (int i=0;i<ans.size();i++){
		if (i==0) cout << ans[i];
		else cout << ' ' << ans[i];
	}
	return 0;
}
