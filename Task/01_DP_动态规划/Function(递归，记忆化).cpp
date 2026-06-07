#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mark[30][30][30] = {0};
ll w(ll a,ll b,ll c)
{
	if (a<=0||b<=0||c<=0) return 1;
	else if (a>20||b>20||c>20) return w(20,20,20);
	else if (mark[a][b][c]==0){
		if (a<b&&b<c) mark[a][b][c] = w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c);
		else mark[a][b][c] = w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1);
	}
	return mark[a][b][c];
}
int main()
{
	while (1)
	{
		ll a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		if (a==-1&&b==-1&&c==-1) break;
		ll ans = w(a,b,c);
		printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,w(a,b,c));
	}
	return 0;
}
