#include <bits/stdc++.h>
struct Student
{
	int num;
	int a,b;
	int ret = 0;
};
using namespace std;
int main()
{
	int n;
	cin >> n;
	Student stu[n];
	int i;
	for (i=0;i<n;i++)
	{
		cin >> stu[i].num >> stu[i].a >> stu[i].b;
		stu[i].ret = stu[i].a*7+stu[i].b*3;
	}
	for (i=0;i<n;i++)
	{
		if (stu[i].a+stu[i].b>140&&stu[i].ret>=800)
		{
			cout << "Excellent" << endl;
		}else{
			cout << "Not excellent" << endl;
		}
	}
	return 0;
	
}
