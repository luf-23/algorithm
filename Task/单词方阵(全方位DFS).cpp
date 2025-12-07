#include <bits/stdc++.h>
using namespace std;
char tar[] = {'y','i','z','h','o','n','g'};
char mapp[120][120];
char Map[120][120];
int n;
int x[10];
int y[10];
int p;
void dfs(int i,int j,int step)
{
	if (i>n||j>n||i<1||j<1) return;
	if (mapp[i][j]==tar[step])
	{
		x[step] = i;
		y[step] = j;
		if (step==6)
		{
			for (int i=0;i<7;i++)
			{
				Map[x[i]][y[i]] = tar[i];
			}
			return;
		}
		if (p==1) dfs(i+1,j,step+1);
		if (p==2) dfs(i-1,j,step+1);
		if (p==3) dfs(i,j+1,step+1);
		if (p==4) dfs(i,j-1,step+1);
		if (p==5) dfs(i+1,j+1,step+1);
		if (p==6) dfs(i+1,j-1,step+1);
		if (p==7) dfs(i-1,j-1,step+1);
		if (p==8) dfs(i-1,j+1,step+1);
	}
}
int main()
{
	memset(Map,'*',sizeof(Map));
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		getchar();
		for (int j=1;j<=n;j++)
		{
			cin >> mapp[i][j];
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (mapp[i][j]=='y')
			{
				for (p=1;p<=8;p++) dfs(i,j,0);
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			cout << Map[i][j];
		}
		cout << endl;
	}
	return 0;
}
