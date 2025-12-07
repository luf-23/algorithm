#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll fff(ll z,ll m)
{
	while (m!=0)
	{
		ll t = z%m;
		z = m;
		m = t;
	}
	return z;
}
int main()
{
	int n;
	cin >> n;
	string str[n];
	for (int i=0;i<n;i++) cin >> str[i];
	ll z = 0;
	ll m = 1;
	for (int i=0;i<n;i++)
	{
		if (isdigit(str[i][0]))
		{
			int pos = str[i].find('/');
			ll x,y;
			x = 0,y = 0;
			for (int j=0;j<pos;j++) x = x*10 + str[i][j]-'0';
			for (int j=pos+1;j<str[i].length();j++) y = y*10 + str[i][j]-'0';
			z = z*y + m*x;
			m *= y;
			ll gys = fff(z,m);
			z /= gys;
			m /= gys;
		}else if (ispunct(str[i][0]))
		{
			int pos = str[i].find('/');
			ll x,y;
			x = 0,y = 0;
			for (int j=1;j<pos;j++) x = x*10 + str[i][j]-'0';
			for (int j=pos+1;j<str[i].length();j++) y = y*10 + str[i][j]-'0';
			z = z*y - x*m;
			m *= y;
			ll gys = fff(z,m);
			z /= gys;
			m /= gys;
		}
	}
	int flag = 0;
	if (z<0&&m>0||z>0&&m<0) flag = 1;
	if (flag) cout << '-';
	z = abs(z);
	m = abs(m);
	ll zs = z /m;
	z %= m;
	if (zs) cout << zs;
	if (z!=0)
	{
		if (zs!=0) cout << ' ';
		if (flag) cout << '-';
		cout << z << '/' << m;
	}
	if (zs==0&&z==0) cout << 0;
	return 0;
}
