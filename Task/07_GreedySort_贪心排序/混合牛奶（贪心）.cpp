#include <bits/stdc++.h>
using namespace std;
struct NN{
	int dj;
	int cnt;
};
bool cmp(NN x,NN y)
{
	return x.dj <= y.dj;
}
int main()
{
	int need,n;
	cin >> need >> n;
	NN nn[n+1];
	for (int i=1;i<=n;i++)
		cin >> nn[i].dj >> nn[i].cnt;
	sort(nn+1,nn+n+1,cmp);
	int cost = 0;
	int j = 1;
	while (need-nn[j].cnt>=0)
	{
		need -= nn[j].cnt;
		cost += nn[j].dj*nn[j].cnt;
		j++;
	}
	cost += need*nn[j].dj;
	cout << cost << endl;
	return 0;
}
