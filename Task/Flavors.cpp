#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	int n;
	cin >> n;
	vector<pair<ll,ll>>arr;
	int BOOL[n+1] = {0};
	for (int i=1;i<=n;i++){
		int x,y;
		cin >> x >> y;
		arr.push_back({x,y});
		BOOL[x]++;
	}
	ll ans = 0;
	vector<ll>num;
	sort(arr.begin(),arr.end());
	for (int i=0;i<arr.size();i++){
		if (BOOL[arr[i].first]>=2){
			i += BOOL[arr[i].first]-1;
			ans = max(ans,arr[i-1].second/2+arr[i].second);
		}
		num.push_back(arr[i].second);
	}
	sort(num.begin(),num.end(),greater<ll>());
	ans = max(ans,num[0]+num[1]);
	cout << ans;
	return 0;
}
