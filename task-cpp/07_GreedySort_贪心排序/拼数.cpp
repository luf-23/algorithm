#include <bits/stdc++.h>
using namespace std;
struct Num{
	string a;
};
bool cmp(Num x,Num y)
{
	return (x.a+y.a >y.a+x.a);
}

int main()
{
	int n;
	cin >> n;
	Num num[n+1];
	for (int i=1;i<=n;i++)
	{
		cin >> num[i].a;
	}
	sort(num+1,num+n+1,cmp);
	for (int i=1;i<=n;i++)
		cout << num[i].a;
	return 0;
}
