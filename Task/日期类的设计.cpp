#include<iostream>
using namespace std;

//你提交的代码在这里
class Date{
private:
	int Y,M,D;
public:
	Date(int y=2015,int m=5,int d=20) {Y=y,M=m,D=d;}
	int GetYear() {return Y;}
	int GetMonth() {return M;}
	int GetDay() {return D;}
	void Show() {cout << Y << '-' << M << '-' << D << '\n';}
	void Set(int y=2050,int m=12,int d=1) {Y=y,M=m,D=d;}
};
int main()
{
	Date d1;
	cout<<"Show object d1:";
	cout<<d1.GetYear()<<"-"<<d1.GetMonth()<<"-"<<d1.GetDay()<<endl;
	int y,m,d;
	cin>>y>>m>>d;
	Date d2(y,m,d);
	cout<<"Show object d2:";
	cout<<d2.GetYear()<<"-"<<d2.GetMonth()<<"-"<<d2.GetDay()<<endl;
	cin>>y>>m>>d;
	cout<<"Reset and Show object d1:";
	d1.Set(y,m,d);
	d1.Show();
	cout<<"Reset and Show object d2:";
	d2.Set();
	d2.Show();
	return 0;
}
