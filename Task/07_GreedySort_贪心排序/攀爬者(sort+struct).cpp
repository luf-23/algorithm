#include <bits/stdc++.h>
using namespace std;
struct Location{
	int x,y,z;
};
bool cmp(Location A,Location B)
{
	return A.z < B.z;
}
int main()
{
	double sum = 0;
	int n;
	cin >> n;
	Location loc[n+1];
	for (int i=1;i<=n;i++)
		cin >> loc[i].x >> loc[i].y >> loc[i].z;
	sort(loc+1,loc+n+1,cmp);
	double dis;
	for (int i=1;i<=n-1;i++)
	{
		dis = sqrt((loc[i].x-loc[i+1].x)*(loc[i].x-loc[i+1].x)+(loc[i].y-loc[i+1].y)*(loc[i].y-loc[i+1].y)+(loc[i].z-loc[i+1].z)*(loc[i].z-loc[i+1].z));
		sum += dis;
	}
	//sum += sqrt((loc[n].x-loc[1].x)*(loc[n].x-loc[1].x)+(loc[n].y-loc[1].y)*(loc[n].y-loc[1].y)+(loc[n].z-loc[1].z)*(loc[n].z-loc[1].z));
	cout << fixed << setprecision(3) << sum << endl;
	return 0;
}
