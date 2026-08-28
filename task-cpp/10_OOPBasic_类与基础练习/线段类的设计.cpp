#include<iostream>
#include<cmath>
using namespace std;

//你提交的代码在这里
class Line{
private:
	double sx,sy,tx,ty;
public:
	Line(double ssx=0,double ssy=0,double ttx=0,double tty=0){
		sx = ssx,sy= ssy,tx = ttx,ty = tty;
	}
	void Show(){
		cout << '(' << sx << ',' << sy << ')' << "--" << '(' << tx << ',' << ty << ')' << "length=" << sqrt((sx-tx)*(sx-tx)+(sy-ty)*(sy-ty)) << '\n';
	}
	void Set(){
		sx = 1,sy = 5,tx = 8,ty = 4;
	}
	void Set(double ssx,double ssy,double ttx,double tty){
		sx = ssx,sy = ssy,tx = ttx,ty = tty;
	}
};
int main()
{
	Line L1;
	cout<<"Show object L1:";
	L1.Show();
	double x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	Line L2(x1,y1,x2,y2);
	cout<<"Show object L2:";
	L2.Show();
	cin>>x1>>y1>>x2>>y2;
	cout<<"Reset and Show object L1:";
	L1.Set(x1,y1,x2,y2);
	L1.Show();
	cout<<"Reset and Show object L2:";
	L2.Set();
	L2.Show();
	return 0;
}
