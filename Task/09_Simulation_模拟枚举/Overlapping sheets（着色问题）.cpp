#include <bits/stdc++.h>
using namespace std;
int main()
{
	int mapp[120][120];
	for (int i=0;i<120;i++){
		for (int j=0;j<120;j++){
			mapp[i][j] = 0;
		}
	}
	int n;
	cin >> n;
	while (n--)
	{
		int x1,x2,y1,y2;
		cin >> x1 >> x2 >> y1 >> y2;
		x1++;
		y1++;//都加1，让点坐标变成方格坐标！！！
		for (int i=x1;i<=x2;i++){
			for (int j=y1;j<=y2;j++){
				mapp[i][j] = 1;
			}
		}
	}
	int ans = 0;
	for (int i=1;i<=100;i++){
		for (int j=1;j<=100;j++){
			if (mapp[i][j]==1){
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
