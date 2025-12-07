#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,na,nb;
	cin >> n >> na >> nb;
	int cnt1 = 0;
	int cnt2 = 0;
	int NA[na];
	int NB[nb];
	int i,j;
	for (i=0;i<na;i++)
	{
		cin >> NA[i];
	}
	for (i=0;i<nb;i++)
	{
		cin >> NB[i];
	}
	int num[5][5] = {
		0,-1,1,1,-1,
		1,0,-1,1,-1,
		-1,1,0,-1,1,
		-1,-1,1,0,1,
		1,1,-1,-1,0};
	for (i=0;i<n;i++)
	{
		if(num[NA[i%na]][NB[i%nb]]==0)
		{
			continue;
		}else if (num[NA[i%na]][NB[i%nb]]==1)
		{
			cnt1 += 1;
		}else if (num[NA[i%na]][NB[i%nb]]==-1)
		{
			cnt2 += 1;
		}
	}
	cout << cnt1 << ' ' << cnt2 << endl;
	return 0;
}
