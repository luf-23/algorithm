#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
int t[3000000][77];
int cur;
map<char,int>mp;
int cnt[3000020];
void insert(string str){
	int p = 0;
	for (int i=0;i<str.length();i++){
		if (!t[p][mp[str[i]]]) t[p][mp[str[i]]] = ++cur;
		p = t[p][mp[str[i]]];
		cnt[p]++;
	}
}
int query(string str){
	int p = 0;
	for (int i=0;i<str.length();i++){
		if (!t[p][mp[str[i]]]) return 0;
		p = t[p][mp[str[i]]];
	}
	return cnt[p];
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int c = 0;
	for (int i='a';i<='z';i++) mp[i] = ++c;
	for (int i='A';i<='Z';i++) mp[i] = ++c;
	for (int i='0';i<='9';i++) mp[i] = ++c;
	int tt;
	cin >> tt;
	while (tt--){
		cin >> n >> q;
		for (int i=0;i<=cur;i++){
			cnt[i] = 0;
			for (int j=1;j<=c;j++){
				t[i][j] = 0;
			}
		}
		cur = 0;
		for (int i=1;i<=n;i++){
			string str;
			cin >> str;
			insert(str);
		}
		while (q--){
			string str;
			cin >> str;
			int ans = query(str);
			cout << ans << '\n';
		}
	}
	return 0;
}
