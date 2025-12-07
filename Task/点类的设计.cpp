#include<iostream>
using namespace std;
//你提交的代码在这里
class Point{
private:
	int x,y;
	
public:
	Point(int xx=10,int yy=16);
	void Show();
	void Set(int xx,int yy);
};
Point::Point(int xx,int yy){
	x = xx,y = yy;
}
void Point::Show(){
	cout << '(' << x << ',' << y << ')' << '\n';
}
void Point::Set(int xx,int yy){
	x = xx,y = yy;
}
int main()
{
	Point p1,p2(20,100);
	cout<<"Show object p1:";
	p1.Show();
	cout<<"Show object p2:";
	p2.Show();
	int x,y;
	cin>>x>>y;
	cout<<"Reset and Show object p1:";
	p1.Set(x,y);
	p1.Show();
	cin>>x>>y;
	cout<<"Reset and Show object p2:";
	p2.Set(x,y);
	p2.Show();
	return 0;
}
