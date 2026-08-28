#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool ishuiwen(ll x)
{
	ll num[35] = {0};
	memset(num,0,sizeof (num));
	ll len = 0;
	while (x)
	{
		num[++len] = x%10;
		x /= 10;
	}
	for (int i=1,j=len;i<=len,j>=1;i++,j--)
	{
		if (num[i]!=num[j]) return false;
	}
	return true;
}
int main()
{
	ll x;
	cin >> x;
	ll flag = 0;
	ll cnt = 0;
	while (1)
	{
		if (ishuiwen(x)) break;
		else if (!ishuiwen(x)&&flag==0)
		{
			cout << x;
			flag = 1;
		}
		ll y = x;
		ll len = 0;
		while (y)
		{
			y /= 10;
			len++;
		}
		y = x;
		ll daoxu = 0;
		for (int i=1;i<=len;i++)
		{
			daoxu = daoxu*10 + y%10;
			y /= 10;
		}
		x = x + daoxu;
		cout << "--->" << x;
		cnt++;
	}
	if (flag==1) cout << endl << cnt;
	else cout << x << endl << 0;
	return 0;
}
