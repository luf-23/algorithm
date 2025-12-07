#include <bits/stdc++.h>
using namespace std;
struct Student{
	int a,b,c;
	int sum;
};
int main()
{
	int n;
	cin >> n;
	Student s[n];
	for (int i=0;i<n;i++)
	{
		cin >> s[i].a >> s[i].b >> s[i].c;
		s[i].sum = s[i].a + s[i].b + s[i].c;
	}
	int cnt = 0;
	for (int i=0;i<n-1;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			if (abs(s[i].a-s[j].a)<=5&&abs(s[i].b-s[j].b)<=5&&abs(s[i].c-s[j].c)<=5&&abs(s[i].sum-s[j].sum)<=10)
			{
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
