#include <bits/stdc++.h>
using namespace std;
int main()
{
	//结论：一个数a在区间[1,x]的倍数的个数为x/a，这里要注意拿x/d与y/d最小的数相除区间的左端点l时个数应为： l/min(x/d,l/d)+(l%min(x/d,l/d)!=0) 因为当不能整除时我们只有取后一个数与最小值相乘才能在区间[l,r]内，答案即为最大值在[1,r]区间的倍数的个数-最小值在区间[1,l]的倍数+1。
	int x,y,l,r;
	cin >> x >> y >> l >> r;
	int a,b;
	a = min(x,y);
	b = max(x,y);
	int t = __gcd(a,b);
	a /= t;
	b /= t;
	int v1 = l/a;
	int v2 = r/b;
	int ans;
	if (l%a==0) ans = v2-v1+1;
	else ans = v2-v1;
	if (ans<0) cout << 0;
	else cout << ans;
	return 0;
}
