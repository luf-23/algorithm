#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
void write(int x){
	if(x<0)putchar('-'),x=-x; // 注意取反 
	if(x<10)putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
using ll = long long int;

ll n;
double a[15];
bool isTriangle(double x, double y, double z) {
	return (x + y > z) && (x + z > y) && (y + z > x);
}

double getArea(double a, double b, double c) {
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

bool cmp(double x, double y) {
	return x > y;
}

void solve()
{
	for (ll i = 1; i <= n; i++) {
		a[i] = read();
	}
	sort(a + 1, a + 1 + n, cmp);
	
	double ans = 0.0;
	for (ll i = 1; i <= n - 2; ) {
		double x = a[i], y = a[i + 1], z = a[i + 2];
		if (!isTriangle(x, y, z)) {
			i++;
			continue;
		}
		i += 3;
		//cout << x << "  " << y << "  " << z << "   Area " << getArea(x, y, z) << '\n';
		ans += getArea(x, y, z);
	}
	
	double ans2 = 0.0;
	sort(a + 1, a + 1 + n);
	for (ll i = 1; i <= n - 2; ) {
		double x = a[i], y = a[i + 1], z = a[i + 2];
		if (!isTriangle(x, y, z)) {
			i++;
			continue;
		}
		i += 3;
		//cout << x << "  " << y << "  " << z << "   Area " << getArea(x, y, z) << '\n';
		ans2 += getArea(x, y, z);
	}
	
	printf("%.2lf\n", max(ans, ans2));
}


int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0); cout.tie(0);
//	
	
	while (cin >> n && n)
	{
		solve();
	}
	
	return 0;
}
