#include <bits/stdc++.h>
using namespace std;
struct MV{
	int m,v;
	double s;
};
bool cmp(MV x,MV y)
{
	return x.s >= y.s;
}
int main()
{
	int n,t;
	cin >> n >> t;
	if (n<=0)
	{
		cout << "0.00";
		exit(EXIT_SUCCESS);
	}
	MV mv[n+1];
	for (int i=1;i<=n;i++)
	{
		cin >> mv[i].m >> mv[i].v;
		mv[i].s = mv[i].v/(mv[i].m*1.0);
	}
	sort(mv+1,mv+n+1,cmp);
	double sum = 0;
	int cnt = 0;//重量
	int i;
	for (i=1;i<=n;i++)
	{
		if (cnt+mv[i].m<=t)
		{
			cnt += mv[i].m;
			sum += mv[i].v;
		}else{
			break;
		}
	}
	sum += (t-cnt)*mv[i].s;
	cout << fixed << setprecision(2) << sum << endl;
	return 0;
}
