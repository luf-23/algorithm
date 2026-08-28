#include <stdio.h>
int main()
{
	int a, b, i, j, c = 0, k , s=0, sum;
	scanf("%d %d", &a, &b);
	for (i = a; i <= b; i++)
	{
		for (j = 1; j < 10; j++)
		{
			k = i * j;
			sum = 0;
			while (k)
			{
				sum += k % 10;
				k /= 10;
			}
			if (j >= 2 && s != sum)
				break;
			s = sum;
		}
		if (j == 10)//从1乘到9，s==sum，满足条件
		{
			c++;
			printf("%d(%d)\n", i, sum);
		}
	}
	if (!c) 
		printf("None");
	return 0;
}
