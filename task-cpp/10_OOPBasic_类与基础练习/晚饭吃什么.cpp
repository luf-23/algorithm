#include<stdio.h>
int main()
{   int a;
	printf("===================今天晚饭吃什么？==================\n");
	printf("1 武汉热干面\n");
	printf("2 西关牛杂\n");
	printf("3 关东煮\n");
	printf("4 鸭血粉丝\n");
	printf("5 麻辣香锅\n");
	printf("6 香酥牛肉饼\n");
	printf("7 带馅彩色面\n");
	printf("8 四川担担面\n");
	printf("9 兰州拉面\n");
	printf("10 土\n\n\n");
	printf("你的选择是");
	scanf("%d",&a);
	switch(a)
	{
		case 1:printf("热气腾腾，回味无穷。\n");break;
		case 2:printf("肉美、汤鲜、味香、色佳\n");break;
		case 3:printf("诱人的香味，口感别致细腻，食过后口齿生香、回味绵长。\n");break;
		case 4:printf("热气升腾，香气就随之在口内游走如小龙。\n");break;
		case 5:printf("辣而不燥，鲜而不腻，麻味绵长，香气扑鼻。\n");break;
		case 6:printf("表皮酥脆碰牙即碎，饼内却柔嫩异常，油面皮香味加麻麻的葱花牛肉。\n");break;
		case 7:printf("如赏美景，景致人心怡，色彩和谐，沁人心脾，便食欲贲张，美食过后，久久回味。\n");break;
		case 8:printf("习大大极力推荐。\n");break;
		case 9:printf("美味妇孺皆知，欲罢不能。\n");break;
		case 10:printf("双十一钱包已掏空，穷的只能吃土了。\n");break;
		
	}
	
	return 0;
}
