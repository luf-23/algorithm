#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<pair<int,int>>arr;
	for (int i=1;i<=9;i++){
		if (n%i==0){
			arr.push_back(make_pair(i,n/i));
		}
	}
	for (int i=0;i<=n;i++){
		int ans = -1;
		for (int j=0;j<arr.size();j++){
			if (i%(arr[j].second)==0){
				ans = arr[j].first;
				break;
			}
		}
		if (ans==-1) cout << '-';
		else cout << ans;
	}
	return 0;
}
