/*如果两人的距离是奇数，那么永远逮不到。
  如果有任何一个人和 Vika 的距离是偶数，那就一定能逮到，可以把她逼到墙角后手能使两人距离单调不增。 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n,m,k;
		cin >> n >> m >> k;
		int x,y;
		cin >> x >> y;
		int X[k];
		int Y[k];
		for (int i=0;i<k;i++)
		{
			cin >> X[i] >> Y[i];
		}
		int flag = 0;
		for (int i=0;i<k;i++)
		{
			int ans = abs(X[i]-x)+abs(Y[i]-y);
			if (ans%2==0)
			{
				flag = 1;
				break;
			}
		}
		if (flag==1) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}
