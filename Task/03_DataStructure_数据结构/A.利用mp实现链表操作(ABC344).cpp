#include <bits/stdc++.h>
#define int long long
using namespace std;
map<int,int>fa;
int num[200005];
map<int,int>mp;
int n,q;
int st,ed;
signed main()
{
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> num[i];
	}
	st = num[1];
	ed = num[n];
	for (int i=1;i<=n-1;i++){
		mp[num[i]] = num[i+1];
	}
	for (int i=2;i<=n;i++){
		fa[num[i]] = num[i-1];
	}
	cin >> q;
	for (int i=1;i<=q;i++){
		int op;
		cin >> op;
		if (op==1){
			int x,y;
			cin >> x >> y;
			if (x!=ed){
				int t = mp[x];
				mp[x] = y;
				mp[y] = t;
				fa[y] = x;
				fa[mp[y]] = y;
			}else{
				mp[x] = y;
				fa[y] = x;
				ed = y;
			}
		}else if (op==2){
			int x;
			cin >> x;
			if (x!=st&&x!=ed){
				mp[fa[x]] = mp[x];
				fa[mp[fa[x]]] = fa[x];
			}else if (x==st){
				st = mp[st];
			}else if (x==ed){
				ed = fa[ed];
			}
		}
	}
	while (st!=ed){
		cout << st << ' ';
		st = mp[st];
	}
	cout << ed;
	return 0;
}
