#include <bits/stdc++.h>
using namespace std;
int main()
{
	int h,w,k;
	cin >> h >> w >> k;
	char mapp[h+1][w+1];
	for (int i=1;i<=h;i++){
		getchar();
		for (int j=1;j<=w;j++){
			cin >> mapp[i][j];
		}
	}
	int x[h+1][w+1];
	int point[h+1][w+1];
	memset(x,0,sizeof(x));
	memset(point,0,sizeof(point));
	int ans = 1e8;
	for (int i=1;i<=h;i++){
		for (int j=1;j<=w;j++){
			x[i][j] = x[i][j-1] + (mapp[i][j]=='x');
			point[i][j] = point[i][j-1] + (mapp[i][j]=='.');
		}
	}
	for (int i=1;i<=h;i++){
		for (int j=1;j+k-1<=w;j++){
			if (x[i][j+k-1]-x[i][j-1]==0){
				ans = min(ans,point[i][j+k-1]-point[i][j-1]);
			}
		}
	}
	memset(x,0,sizeof(x));
	memset(point,0,sizeof(point));
	for (int j=1;j<=w;j++){
		for (int i=1;i<=h;i++){
			x[i][j] = x[i-1][j] + (mapp[i][j]=='x');
			point[i][j] = point[i-1][j] + (mapp[i][j]=='.');
		}
	}
	for (int j=1;j<=w;j++){
		for (int i=1;i+k-1<=h;i++){
			if (x[i+k-1][j]-x[i-1][j]==0){
				ans = min(ans,point[i+k-1][j]-point[i-1][j]);
			}
		}
	}
	cout << (ans==1e8 ? -1 : ans);
	return 0;
}
