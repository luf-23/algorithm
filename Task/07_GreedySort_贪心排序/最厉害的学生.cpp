#include <bits/stdc++.h>
using namespace std;
struct Student {
	char name[10];
	int x,y,z;
};
int main()
{
	int n;
	cin >> n;
	int max_v[n];
	Student stu[n];
	int i;
	for (i=0;i<n;i++)
	{
		cin >> stu[i].name >> stu[i].x >> stu[i].y >> stu[i].z;
		max_v[i] = stu[i].x+stu[i].y+stu[i].z;
	}
	sort(max_v+0,max_v+n);
	for (i=0;i<n;i++)
	{
		if (stu[i].x+stu[i].y+stu[i].z==max_v[n-1])
		{
			cout << stu[i].name << ' ' << stu[i].x << ' ' << stu[i].y << ' ' << stu[i].z;
			break;
		}
	}
	//int ret;
	//int Max_v = 0;
	//for (i=n-1;i>=0;i--)
	//{
	///	if (Max_v<max_v[i])
	//	{
	//		Max_v = max_v[i];
	//		ret = i;
	//	}
	//}
	//cout << stu[ret].name << ' ' << stu[ret].x << ' ' << stu[ret].y << ' ' << stu[ret].z;
}
