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
	}
	for (int i=1;i<=m;i++){
		int op;
		cin >> op;
		if (op==1){
			int x,y,k;
			cin >> x >> y >> k;
			add(x,k);
			add(y+1,-k);
		}else{
			int x;
			cin >> x;
			cout << a[x] + query(x) << endl;
		}
	}
	return 0;
}
