//程序设计基础一 综合作业
//主函数结构参考

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void menu();  //功能菜单函数

int main()
{
	char choose;
	int  flag=1;
	
	while (flag)
	{
		system("cls");
		menu();                  //调用功能菜单函数,显示菜单项。
		printf("      请选择:");
		choose=getchar();
		
		switch(choose)
		{
		case '1':
			//调用功能模块1函数；
			getchar();
			
			break;
		case '2':
			//调用功能模块2函数；
			
			getchar();
			break;
		case '3':
			//调用功能模块3函数；
			
			getchar();
			break;
		case '4':
			//调用功能模块...n函数；
			
			getchar();
			break;
		case '5':
			//调用功能模块2函数；
			
			getchar();
			break;
		case '6':
			//调用功能模块2函数；
			getchar();
			break;
		case '0':
			//结束程序运行！
			flag=0;
			printf("\n     *** The End! ***\n");
			break;
			default: printf("\n    Wrong Selection !（选择错误，重选）\n");
			
		}
		//getchar();
		getchar();
	}
}

void menu()   //  综合作业功能菜单
{
	printf(" \n                 学 生 成 绩 统 计 与 分 析 系 统\n");
	printf(" \n                          菜  单\n\n");
	printf(" \n           1.    输 入  \n");
	printf(" \n           2.    显 示 \n");
	printf(" \n           3.    排 序 \n");
	printf(" \n           4.    删 除 \n");
	printf(" \n           5.    插 入 \n");
	printf(" \n           6.    查 找 \n");
	printf(" \n           0.    退      出\n\n");
}

/*5 6 7 8 9 3 4 0 2 1*/

