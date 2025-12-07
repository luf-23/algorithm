#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int num[n+1];
	int i;
	for (i=0;i<=n;i++)
	{
		cin >> num[i];
	}
	reverse(num+0,num+n+1);
	if (n==0)
	{
		printf("%d",num[0]);
		exit(EXIT_SUCCESS);
	}
	//for (i=0;i<=n;i++)
	//{
	//	cout << num[i] << ' ';
	//}
	int cnt = n;
	while (cnt>=0)
	{
		if (num[cnt]!=0)
		{
			break;
		}
		cnt--;
	}
	if (num[cnt]==1)
	{
		printf("x^%d",cnt);
	}else if (num[cnt]==-1){
		printf("-x^%d",cnt);
	}else{
		printf("%dx^%d",num[cnt],cnt);
	}
	cnt -= 1;
	while (cnt>1)
	{
		if (num[cnt]==0)
		{
			cnt--;
			continue;
		}else{
			if (num[cnt]<0)
			{
				if (num[cnt]==-1)
				{
					printf("-x^%d",cnt);
				}else{
					printf("%dx^%d",num[cnt],cnt);
				}
			}else if (num[cnt]>0)
			{
				if (num[cnt]==1)
				{
					printf("+x^%d",cnt);
				}else{
					printf("+%dx^%d",num[cnt],cnt);
				}
			}
		}
		cnt--;
	}
	if (num[cnt]<0)
	{
		if (num[cnt]==-1)
		{
			printf("-x",cnt);
		}else{
			printf("%dx",num[cnt]);
		}
	}else if (num[cnt]>0)
	{
		if (num[cnt]==1)
		{
			printf("+x");
		}else{
			printf("+%dx",num[cnt]);
		}
	}
	cnt--;
	if (num[0]!=0)
	{
		if (num[0]<0)
		{
			printf("%d",num[0]);
		}else if (num[0]>0)
		{
			printf("+%d",num[0]);
		}
	}
	return 0;
}
