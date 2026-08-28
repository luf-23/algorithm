#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[3] = {0};
	char s1,s2;
	int cnt = 0;
	while (scanf("%c:=%c;",&s1,&s2)!=EOF)
	{
		a[s1-'a']= s2>='0'&&s2<='9' ? s2-'0':a[s2-'a'];
		cnt++;
	}
	printf("%d %d %d",a[0],a[1],a[2]);
	return 0;
}
