#include <bits/stdc++.h>
using namespace std;
int n,r;
int num[30];
void dfs(int step)
{
	if (step==r+1)
	{
		for (int i=1;i<=r;i++)
		{
			cout << setw(3) << num[i];
		}
		cout << endl;
		return;
	}
	for (int i=num[step-1]+1;i<=n;i++)
	{
		num[step] = i;
		dfs(step+1);
	}
}
int main()
{
	cin >> n >> r;
	dfs(1);
	return 0;
}
