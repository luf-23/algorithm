#include <bits/stdc++.h>
int num[10][10];
using namespace std;
int n;
bool ishang(int x,int i)
{
	for (int j=1;j<=n;j++)
	{
		if (x<num[i][j]) return false;
	}
	return true;
}
bool islie(int x,int j)
{
	for (int i=1;i<=n;i++)
	{
		if (x>num[i][j]) return false;
	}
	return true;
}
int main()
{
	cin >> n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			cin >> num[i][j];
	int px,py;
	px = -1;
	py = -1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (ishang(num[i][j],i)&&islie(num[i][j],j))
			{
				px = i;
				py = j;
			}
		}
	}
	if (px!=-1)
	{
		cout << px-1 << ' ' << py-1;
	}else{
		cout << "NONE";
	}
	return 0;
}
