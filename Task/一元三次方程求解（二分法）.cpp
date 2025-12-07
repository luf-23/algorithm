#include <bits/stdc++.h>
using namespace std;
double a,b,c,d;
using ll = long long;
double Fx(double x)
{
	return a*x*x*x + b*x*x + c*x +d;
}
int main()
{
	cin >> a >> b >> c >> d;
	int cnt = 0;
	double l,r,mid;
	for (int i=-100;i<100;i++)
	{
		l = i;
		r = l + 1;
		if (!Fx(l))
		{
			cnt++;
			cout << fixed << setprecision(2) << l << ' ';
		}
		if (Fx(l)*Fx(r)<0)
		{
			while (r-l>=0.0001)
			{
				mid = (l+r)/2.0;
				if (Fx(mid)*Fx(r)<=0)
				{
					l = mid;
				}else{
					r = mid;
				}
			}
			cout << fixed << setprecision(2) << l << ' ';
			cnt++;
		}
		if (cnt==3) break;
	}
	return 0;
}
