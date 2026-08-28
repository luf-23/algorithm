#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll dt[100005];
ll t[100005];
int n,m;
ll a,b;
ll lowbit(ll x)
{
	return x&(-x);
}
void add(ll *num,ll pos,ll val)
{
	while (pos<=n){
		num[pos] += val;
		pos += lowbit(pos);
	}
}
ll getsum(ll *num,ll x)
{
	ll sum = 0;
	while (x){
		sum += num[x];
		x -= lowbit(x);
	}
	return sum;
}
int main()
{
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a;
		b = a - b;
		add(t,i,b);
		add(dt,i,b*(i-1));
		b = a;
	}
	for (int i=1;i<=m;i++){
		int op;
		cin >> op;
		if (op==1){
			ll x,y,val;
			cin >> x >> y >> val;
			add(t,x,val);
			add(t,y+1,-val);
			add(dt,x,(x-1)*val);
			add(dt,y+1,-val*y);
		}else{
			ll x,y;
			cin >> x >> y;
			ll ans = (y*getsum(t,y)-(x-1)*getsum(t,x-1))-(getsum(dt,y)-getsum(dt,x-1));
			cout << ans << endl;
		}
	}
	return 0;
}
