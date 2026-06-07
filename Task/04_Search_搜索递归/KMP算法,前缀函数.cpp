#include <bits/stdc++.h>
#define int long long
using namespace std;
int t[1000005];
signed main(){
	string str,tar;
	cin >> str >> tar;
	string cur = tar + '&' + str;
	t[0] = 0;
	for (int i=1;i<cur.length();i++){
		int j = t[i-1];
		while (j>0&&cur[j]!=cur[i]) j = t[j-1];
		if (cur[j]==cur[i]) j++;
		t[i] = j;
	}
	vector<int>ans;
	for (int i=1;i<cur.length();i++){
		if (t[i]==tar.length()){
			ans.push_back(i-2*tar.length());
		}
	}
	cout << ans.size() << '\n';
	for (auto e : ans) cout << e << ' ';
	cout << '\n';
	for (auto e : ans){
		string s = str.substr(e,tar.length());
		cout << s << '\n';
	}
	return 0;
}
