#include <bits/stdc++.h>
using namespace std;
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	cout.tie(nullptr);
	int n;
	cin >> n;
	map<int,int>mp;
	int x;
	for (int i=1;i<=n;i++){
		cin >> x;
		mp[i] = x;
	}
	int i = 1;
	int BOOL[n+1] = {0};
	while (!BOOL[i]){
		BOOL[i] = 1;
		i = mp[i];
	}
	vector<int>ans;
	int j = i;
	do{
		ans.push_back(j);
		j = mp[j];
	}while(j!=i);
	cout << ans.size() << endl;
	for (int i=0;i<ans.size();i++){
		cout << ans[i] << ' ';
	}
	return 0;
}
