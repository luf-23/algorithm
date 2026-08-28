#include <stdio.h>
#include <string.h>
int main()
{
	char str[100];
	gets(str);
	int i;
	int cnt = 0;
	for (i=0;i<strlen(str);i++)
	{
		if (str[i]!=' ')
		{
			cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
}
