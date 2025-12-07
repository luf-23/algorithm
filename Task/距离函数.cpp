#include <bits/stdc++.h>
using namespace std;
int main()
{
	struct xy
	{
		double x,y;
	};
	struct xy xy1,xy2,xy3;
	cin >> xy1.x >> xy1.y;
	cin >> xy2.x >> xy2.y;
	cin >> xy3.x >> xy3.y;
	float d1,d2,d3;
	d1 = sqrt((xy1.x-xy2.x)*(xy1.x-xy2.x)+(xy1.y-xy2.y)*(xy1.y-xy2.y));
	d2 = sqrt((xy2.x-xy3.x)*(xy2.x-xy3.x)+(xy2.y-xy3.y)*(xy2.y-xy3.y));
	d3 = sqrt((xy3.x-xy1.x)*(xy3.x-xy1.x)+(xy3.y-xy1.y)*(xy3.y-xy1.y));
	double ret = d1 + d2 + d3;
	cout << fixed << setprecision(2) << ret;
}
