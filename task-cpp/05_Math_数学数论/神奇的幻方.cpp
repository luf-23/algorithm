#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int num[n+1][n+1] = {0};
	int i,j;
	int cnt = 1;
	int p,q;
	num[1][n/2+1] = cnt;
	p = 1;
	q = n/2+1;
	while (cnt<=n*n-1)
	{
		if (p==1&&q!=n)
		{
			cnt += 1;
			p = n;
			q = q+1;
			num[p][q] = cnt;
		}else if (p!=1&&q==n)
		{
			cnt += 1;
			p = p-1;
			q = 1;
			num[p][q] = cnt;
		}else if (p==1&&q==n)
		{
			cnt += 1;
			p = p+1;
			num[p][q] = cnt;
		}else{
			if (num[p-1][q+1]==0)
			{
				cnt += 1;
				p = p-1;
				q = q+1;
				num[p][q] = cnt;
			}else{
				p = p+1;
				cnt += 1;
				num[p][q] = cnt;
			}
		}
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			cout << num[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
