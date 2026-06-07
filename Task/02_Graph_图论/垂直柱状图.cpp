#include <bits/stdc++.h>
using namespace std;
int main()
{
	char x[100][26];
	int BOOL[26] = {0};
	int i,j;
	for (i=0;i<100;i++)
		for (j=0;j<26;j++)
			x[i][j] = ' ';
	char a = 'A';
	int cnt = 0;
	for (i=0;i<26;i++)
	{
		x[0][i] = 'A'+ cnt;
		cnt++;
	}
	//for (i=0;i<51;i++)
	//{
	//	for (j=0;j<51;j++)
	//	{
	//		cout << x[i][j] << ' '; 
	//	}
	//	cout << endl;
	//}
	while ((a=getchar())!=EOF)
	{
		if (a != '\n')
		{
			if (a>='A'&&a<='Z')
			{
				BOOL[a-'A']++;
			}
		}
	}
	for (i=0;i<26;i++)
	{
		if (BOOL[i]!=0)
		{
			for (j=1;j<=BOOL[i];j++)
			{
				x[j][i] = '*';
			}
		}
	}
	int max_v = 0;
	for (i=0;i<26;i++)
	{
		if (max_v<BOOL[i])
		{
			max_v = BOOL[i];
		}
	}
	for (i=max_v;i>=0;i--)
	{
		cout << x[i][0];
		for (j=1;j<26;j++)
		{
			cout << ' ' << x[i][j];
		}
		cout << endl;
	}
	return 0;
}
