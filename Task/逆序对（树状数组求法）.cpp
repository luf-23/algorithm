#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
struct Node{
	ll val;
	ll pos;
}node[500005];
ll tree[500005];
int lowbit(int x)
{
	return x&(-x);
}
void add(int pos,int x)
{
	while (pos<=n){
		tree[pos] += x;
		pos += lowbit(pos);
	}
}
int query(int x)
{
	int sum = 0;
	while (x>=1){
		sum += tree[x];
		x -= lowbit(x);
	}
	return sum;
}
int main()
{
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> node[i].val;
		node[i].pos = i;
	}
	auto CMP = [&](Node a,Node b){
		if (a.val!=b.val) return a.val < b.val;
		return a.pos < b.pos;
	};
	sort(node+1,node+n+1,CMP);
	ll ans = 0;
	for (int i=1;i<=n;i++){
		add(node[i].pos,1);
		ans += i-query(node[i].pos);
	}
	cout << ans;
	return 0;
}
