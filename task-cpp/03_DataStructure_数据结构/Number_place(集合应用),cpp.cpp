#include <bits/stdc++.h>
using namespace std;
int main()
{
	set<int>row[10],col[10],small[10];
	int x;
	for (int i=1;i<=9;i++)
	{
		for (int j=1;j<=9;j++)
		{
			cin >> x;
			row[i].insert(x);
			col[j].insert(x);
			//cout << (i-1)/3*3+(j-1)/3+1 << ' ';
			small[(i-1)/3*3+(j-1)/3+1].insert(x);
		}
	}
	int flag = 1;
	for (int i=1;i<=9;i++)
	{
		if (row[i].size()!=9) flag = 0;
		if (col[i].size()!=9) flag = 0;
		if (small[i].size()!=9) flag = 0;
		//for (auto it=small[i].begin();it!=small[i].end();++it) cout << *it << endl;
	}
	if (!flag) cout << "No";
	else cout << "Yes";
	return 0;
}
