#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int s[500005];
int lowbit(int x)
{
	return x&(-x);
}
void add(int pos,int val)
{
	while (pos<=n){
		s[pos] += val;
		pos += lowbit(pos);
	}
}
int query(int x)
{
	int sum = 0;
	while (x>=1){
		sum += s[x];
		x -= lowbit(x);
	}
	return sum;
}
int main()
{
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		add(i,a[i]);
	}
	for (int i=1;i<=m;i++){
		int op,x,y;
		cin >> op >> x >> y;
		if (op==1) add(x,y);
		else cout << query(y) - query(x-1) << endl;
	}
	return 0;
}
