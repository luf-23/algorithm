#include <bits/stdc++.h>
using namespace std;
int main()
{
	queue<int> q;
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=n;i++)
		q.push(i);
	int pos = 0;
	while (!q.empty())
	{
		pos++;
		if (pos==m)
		{
			cout << q.front() << ' ';
			q.pop();
			pos = 0;
		}else{
			int temp = q.front();
			q.pop();
			q.push(temp);
		}
	}
	return 0;
}
