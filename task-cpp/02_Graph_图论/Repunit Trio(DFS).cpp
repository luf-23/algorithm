#include <bits/stdc++.h>
using namespace std;
vector<long long>arr;
set<long long>ans;
void dfs(int step,long long ret)
{
	if (step==4){
		ans.insert(ret);
		return;
	}
	for (int i=0;i<=18;i++){
		dfs(step+1,ret+arr[i]);
	}
}
int main()
{
	long long x = 1;
	for (int i=1;i<=20;i++){
		arr.push_back(x);
		x = x*10 + 1;
	}
	dfs(1,0);
	int n;
	cin >> n;
	int pos = 1;
	for (auto ele : ans){
		cout << ele << ' ';
	}
	return 0;
}
