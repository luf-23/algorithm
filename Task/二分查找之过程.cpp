#include <stdio.h>
int main()
{
	int n;
	int x;
	scanf("%d %d",&n,&x);
	int num[n];
	int i;
	for (i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
		if (i>=1)
		{
			if (num[i]<=num[i-1])
			{
				printf("Invalid Value\n");
				return 0;
			}
		}
	}
	int left = 0;
	int right = n-1;
	int middle;
	int pos = -1;
	while (left<=right)
	{
		middle = left + (right-left)/2;
		printf("[%d,%d][%d]\n",left,right,middle);
		if (x>num[middle])
		{
			left = middle + 1;
		}else if (x<num[middle])
		{
			right = middle - 1;
		}else{
			pos = middle;
			break;
		}
	}
	if (pos==-1)
	{
		printf("Not Found");
	}else{
		printf("%d",pos);
	}
	return 0;
}
