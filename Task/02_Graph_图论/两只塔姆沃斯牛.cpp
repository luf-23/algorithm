#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i,j;
	char m[10][10];
	for (i=0;i<10;i++)
	{
		for (j=0;j<10;j++)
		{
			cin >> m[i][j];
		}
	}
	int dx[4] = {-1,0,1,0};
	int dy[4] = {0,1,0,-1};
	int x1,y1,x2,y2;
	for (i=0;i<10;i++)
	{
		for (j=0;j<10;j++)
		{
			if (m[i][j]=='C')
			{
				x1 = i;
				y1 = j;
			}
			if (m[i][j]=='F')
			{
				x2 = i;
				y2 = j;
			}
		}
	}
	int cnt = 0;
	int c,f;
	c = 0,f = 0;
	while (1)
	{
		if (x1+dx[c]>=10||x1+dx[c]<0||y1+dy[c]>=10||y1+dy[c]<0||m[x1+dx[c]][y1+dy[c]]=='*')
		{
			c = (c + 1 ) % 4;
		}else{
			x1 += dx[c];
			y1 += dy[c];
		}
		if (x2+dx[f]>=10||x2+dx[f]<0||y2+dy[f]>=10||y2+dy[f]<0||m[x2+dx[f]][y2+dy[f]]=='*')
		{
			f = (f + 1) % 4;
		}else{
			x2 += dx[f];
			y2 += dy[f];
		}
		cnt++;
		if (x1==x2&&y1==y2)
		{
			cout << cnt << endl;
			break;
		}
		if (cnt>10000)
		{
			cout << 0 << endl;
			break;
		}
	}
	return 0;
}
