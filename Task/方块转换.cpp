#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int flag = 0;
	int k;
	char x;
	char a[n+1][n+1];
	char b[n+1][n+1];
	char ret[n+1][n+1];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			cin >> a[i][j];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			cin >> ret[i][j];
	for (k=1;k<=7;k++)
	{
		memcpy(b,a,sizeof(a));
		int issame = 1;
		if (k==1)
		{
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					b[j][n-i+1] = a[i][j];
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					if (b[i][j]!=ret[i][j])
						issame = 0;
			if (issame==0) continue;
			else break;
		}else if (k==2)
		{
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					b[n-i+1][n-j+1] = a[i][j];
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					if (b[i][j]!=ret[i][j])
						issame = 0;
			if (issame==0) continue;
			else break;
		}else if (k==3)
		{
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					b[n-j+1][i] = a[i][j];
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					if (b[i][j]!=ret[i][j])
						issame = 0;
			if (issame==0) continue;
			else break;
		}else if (k==4)
		{
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					b[i][n-j+1] = a[i][j];
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					if (b[i][j]!=ret[i][j])
						issame = 0;
			if (issame==0) continue;
			else break;
		}else if (k==5)
		{
			char c[n+1][n+1];
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					b[i][n-j+1] = a[i][j];
			for (int x=1;x<=3;x++)
			{
				int is1,is2,is3;
				is1 = is2 = is3 = 1;
				if (x==1)
				{
					for (int i=1;i<=n;i++)
						for (int j=1;j<=n;j++)
							c[j][n-i+1] = b[i][j];
					for (int i=1;i<=n;i++)
						for (int j=1;j<=n;j++)
							if (c[i][j]!=ret[i][j])
								is1 = 0;
				}else if(x==2)
				{
					for (int i=1;i<=n;i++)
						for (int j=1;j<=n;j++)
							c[n-i+1][n-j+1] = b[i][j];
					for (int i=1;i<=n;i++)
						for (int j=1;j<=n;j++)
							if (c[i][j]!=ret[i][j])
								is2 = 0;
				}else if (x==3)
				{
					for (int i=1;i<=n;i++)
						for (int j=1;j<=n;j++)
							c[n-j+1][i] = b[i][j];
					for (int i=1;i<=n;i++)
						for (int j=1;j<=n;j++)
							if (c[i][j]!=ret[i][j])
								is3 = 0;
				}
				if (is1==1&&is2==1&&is3==1)
				{
					flag = 1;
					break;
				}
			}
			if (flag==1) break;
			else continue;
		}else if (k==6)
		{
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					if (a[i][j]!=ret[i][j])
						issame = 0;
			if (issame==0) continue;
			else break;
		}else if (k==7)
		{
			break;
		}
	}
	cout << k << endl;
	return 0;
}
