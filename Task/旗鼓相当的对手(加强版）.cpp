#include <bits/stdc++.h>
using namespace std;
struct Student{
	char name[10];
	int a,b,c;
	int sum;
};
int main()
{
	int n;
	cin >> n;
	Student stu[n];
	int i,j;
	for(i=0; i<n-1; i++)
		for(j=i; j<=n-j; j++) {
		if(stu[i].name>stu[j].name) {
			swap(stu[i].name,stu[j].name);
			swap(stu[i].a,stu[j].a);
			swap(stu[i].b,stu[j].b);
			swap(stu[i].c,stu[j].c);
		}
	}
	for (i=0;i<n;i++){
		cin >> stu[i].name;
		cin >> stu[i].a >> stu[i].b >> stu[i].c;
		stu[i].sum = stu[i].a+stu[i].b+stu[i].c;
	}
	for (i=0;i<n-1;i++){
		for (j=i+1;j<n;j++){
			if (fabs(stu[i].sum-stu[j].sum)<=10&&fabs(stu[i].a-stu[j].a)<=5&&fabs(stu[i].b-stu[j].b)<=5&&fabs(stu[i].c-stu[j].c)<=5){
				cout << stu[i].name << ' ' << stu[j].name << endl;
			}
		}
	}
	return 0;
}
