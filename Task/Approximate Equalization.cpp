#include <bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(int x,int y)
{
	int cnt1 = 0;
	int cnt2 = 0;
	while (x%10==0){
		cnt1++;
		x /= 10;
	}
	while (y%10==0){
		cnt2++;
		y /= 10;
	}
	return cnt1 > cnt2;
}
signed main()
{
	int t;
	cin >> t;
	while (t--){
		int n,m;
		cin >> n >> m;
		int step = n-1;
		int num[n+1];
		for (int i=1;i<=n;i++) cin >> num[i];
		sort(num+1,num+n+1,cmp);
		int cnt = 0;
		int BOOL[n+1] = {0};
		for (int i=1;i<=n;i++){
			if (num[i]%10!=0) break;
			if (i%2==1) BOOL[i] = 1;
		}
		for (int i=1;i<=n;i++){
			if (!BOOL[i]){
				while (num[i]){
					cnt++;
					num[i] /= 10;
				}
			}else{
				while (num[i]%10==0){
					num[i] /= 10;
				}
				while (num[i]){
					cnt++;
					num[i] /= 10;
				}
			}
		}
		if (m==0){
			cout << "Sasha" << '\n';
			continue;
		}
		if (cnt-1>=m) cout << "Sasha" << '\n';
		else cout << "Anna" << '\n';
		
	}
	return 0;
}
