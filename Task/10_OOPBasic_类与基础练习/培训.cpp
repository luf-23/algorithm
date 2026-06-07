#include <bits/stdc++.h>
using namespace std;
struct Student{
	char name[30];
	int age;
	int grade;
};
int main()
{
	int n;
	cin >> n;
	Student stu[n];
	for (int i=0;i<n;i++)
	{
		cin >> stu[i].name >> stu[i].age >> stu[i].grade;
		if ((stu[i].grade*6/5) <= 600)
		{
			(stu[i].grade *= 6) /= 5;
		}else{
			stu[i].grade = 600;
		}
		stu[i].age += 1;
		cout << stu[i].name << ' ' << stu[i].age << ' ' << stu[i].grade << endl;
	}
	return 0;
}
