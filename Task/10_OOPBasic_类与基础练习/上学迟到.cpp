#include <bits/stdc++.h>
using namespace std;
int main()
{
	int s,v;
	scanf("%d %d",&s,&v);
	int t = ceil((s*1.0)/v);
	int cost = t + 10;
	int start = 0;
	if (cost<=480)
	{
		start = 480-cost;
		printf("%02d:%02d",start/60,start%60);
	}else{
		start = cost - 480;
		printf("%02d:%02d",23-start/60,60-start%60);
	}
	return 0;
}
