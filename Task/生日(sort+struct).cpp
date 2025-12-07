#include <bits/stdc++.h>
using namespace std;
struct Student{
	string name;
	int a,b,c;
	int xuhao;
};
bool cmp(Student x,Student y)
{
	if (x.a!=y.a) return x.a < y.a;
	else{
		if (x.b!=y.b) return x.b < y.b;
		else{
			if (x.c!=y.c) return x.c < y.c;
			else{
				return x.xuhao > y.xuhao;
			}
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
		cin >> s[i].name >> s[i].a >> s[i].b >> s[i].c;
		s[i].xuhao = i;
	}
	sort(s+1,s+n+1,cmp);
	for (int i=1;i<=n;i++)
	{
		cout << s[i].name << endl;
	}
	return 0;
}
