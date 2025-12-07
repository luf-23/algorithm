#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,s;
	cin >> n >> s;
	int a,b;
	cin >> a >> b;
	if (n==0||s<=0)
	{
		cout << 0;
		exit(EXIT_SUCCESS);
	}
	int h = a + b;
	vector<int> cost;
	for (int i=1;i<=n;i++)
	{
		int H,C;
		cin >> H >> C;
		if (H<=h) cost.push_back(C);
	}
	sort(cost.begin(),cost.end());
	int cnt = 0;
	int i = 0;
	while (s-cost[i]>=0&&i<cost.size())
	{
		cnt++;
		s -= cost[i];
		i++;
	}
	cout << cnt << endl;
	return 0;
}
