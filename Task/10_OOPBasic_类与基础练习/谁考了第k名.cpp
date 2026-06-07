#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n,k;
	cin >> n >> k;
	priority_queue<pair<float,string>,vector<pair<float,string>>>pq;
	for (int i=1;i<=n;i++)
	{
		string str;
		float score;
		cin >> str >> score;
		pq.push({score,str});
		while (pq.size()>k) pq.pop();
	}
	cout << pq.top().second << ' ' << fixed << setprecision(1) << pq.top().first;
	return 0;
}
