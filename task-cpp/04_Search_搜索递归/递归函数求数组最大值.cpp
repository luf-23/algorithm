#include <stdio.h>
int Max(int num[],int n,int max_v)
{
	if (n==0) return max_v;
	num[n]>max_v ? Max(num,n-1,num[n]) : Max(num,n-1,max_v);
}
int main()
{
	int num[100];
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&num[i]);
	int max_v = Max(num,n,0);
	printf("%d",max_v);
	return 0;
}
