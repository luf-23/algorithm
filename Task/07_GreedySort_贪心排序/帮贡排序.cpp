#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct People{
	string name;
	string zw;
	ll bg;
	int dj;
	int xuhao;
};
int change(People x)
{
	if (x.zw=="BangZhu") return 0;
	else if (x.zw=="FuBangZhu") return 1;
	else if (x.zw=="HuFa") return 2;
	else if (x.zw=="ZhangLao") return 3;
	else if (x.zw=="TangZhu") return 4;
	else if (x.zw=="JingYing") return 5;
	else if (x.zw=="BangZhong") return 6;
}
bool cmp1(People x,People y){
	if (x.bg==y.bg) return x.xuhao < y.xuhao;
	else return x.bg > y.bg;
}
bool cmp2(People x,People y)
{
	if (x.zw!=y.zw) return change(x) < change(y);
	if (x.zw==y.zw&&x.dj!=y.dj) return x.dj > y.dj;
	if (x.zw==y.zw&&x.dj==y.dj) return x.xuhao < y.xuhao;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n;
	cin >> n;
	People p[n];
	for (int i=0;i<n;i++)
	{
		cin >> p[i].name >> p[i].zw >> p[i].bg >> p[i].dj;
		p[i].xuhao = i;
	}
	sort(p+3,p+n,cmp1);
	for (int i=0;i<n;i++)
	{
		if (i==0) p[i].zw = "BangZhu";
		else if (i==1||i==2) p[i].zw = "FuBangZhu";
		else if (i==3||i==4) p[i].zw = "HuFa";
		else if (i>=5&&i<=8) p[i].zw = "ZhangLao";
		else if (i>=9&&i<=15) p[i].zw = "TangZhu";
		else if (i>=16&&i<=40) p[i].zw = "JingYing";
		else p[i].zw = "BangZhong";
	}
	sort(p+3,p+n,cmp2);
	for (int i=0;i<n;i++)
		cout <<p[i].name << ' ' << p[i].zw << ' ' << p[i].dj << endl;
	return 0;
}
