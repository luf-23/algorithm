#include <bits/stdc++.h>
using namespace std;
struct Student{
	int a,b,c;
	int xuhao;
	int sum;
};
bool cmp(Student x,Student y){
	if (x.sum!=y.sum) return x.sum > y.sum;
	else{
		if (x.a!=y.a) return x.a > y.a;
		else{
			return x.xuhao < y.xuhao;
		}
	}
}
int main()
{
	int n;
	cin >> n;
	Student s[n+1];
	for (int i=1;i<=n;i++)
	{
		cin >> s[i].a >> s[i].b >> s[i].c;
		s[i].sum = s[i].a + s[i].b + s[i].c;
		s[i].xuhao = i;
	}
	sort(s+1,s+n+1,cmp);
	for (int i=1;i<=5;i++)
	{
		cout << s[i].xuhao << ' ' << s[i].sum << endl;
	}
	return 0;
}
