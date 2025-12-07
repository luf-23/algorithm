#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long huix = 1;
	long long duiw = 1;
	string h,d;
	cin >> h;
	cin >> d;
	int i;
	for (i=0;i<h.length();i++)
	{
		huix *= (h[i]-'A'+1);
	}
	for (i=0;i<d.length();i++)
	{
		duiw *= (d[i]-'A'+1);
	}
	if ((huix%47)==(duiw%47))
	{
		cout << "GO";
	}else{
		cout << "STAY";
	}
	return 0;
}
