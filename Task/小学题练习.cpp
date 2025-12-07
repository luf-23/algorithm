#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int x,y;
	time_t n;
	int cnt = 0;
	int count = 0;
	printf("请完成10个100以内的加法运算\n");
	while(cnt<10)
	{
		n = time(NULL);
		srand(n);
		x = rand()%100;
		y = rand()%100;
		int sum;
		printf("请输入结果:\n");
		printf("%d+%d=",x,y);
		scanf("%d",&sum);
		if (sum==x+y)
		{
			printf("答案正确\n");
			count++;
		}else{
			printf("答案错误\n");
		}
		cnt++;
	}
	printf("\n你一共答对%d个题\n",count);
	return 0;
}
