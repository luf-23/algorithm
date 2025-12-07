#include <bits/stdc++.h>
using namespace std;
int num[30005];
int fa[30005];
int sum[30005];
int Find(int x)
{
	if (x==fa[x]) return fa[x];
	int temp = Find(fa[x]);
	sum[x] += sum[fa[x]];
	return fa[x] = temp;
}
int main()
{
	int t;
	cin >> t;
	for (int i=1;i<=30005;i++){
		fa[i] = i;
		num[i] = 1;
		sum[i] = 0;
	}
	while (t--){
		char ch;
		int i,j;
		cin >> ch >> i >> j;
		if (ch=='M'){
			int I = Find(i);
			int J = Find(j);
			sum[I] += num[J];
			fa[I] = J;
			num[J] += num[I];
			num[I] = 0;
		}else{
			if (Find(i)!=Find(j)) cout << -1 << endl;
			else cout << abs(sum[i]-sum[j])-1 << endl;
		}
	}
	return 0;
}
