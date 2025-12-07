#include<iostream>
using namespace std;
class Clock{
private:
	int H,M,S;
public:
	Clock(int h=8,int m=16,int s=24);
	void Show();
	void Set(int h,int m,int s);
};
Clock::Clock(int h,int m,int s){
	H = h,S = s,M = m;
}
void Clock::Show(){
	cout << H << ':' << M << ':' << S << '\n';
}
void Clock::Set(int h,int m,int s){
	H = h,M = m,S = s;
}
//你提交的代码在这里
int main()
{
	Clock c1,c2(12,25,38);
	cout<<"Show object c1:";
	c1.Show();
	cout<<"Show object c2:";
	c2.Show();
	int h,m,s;
	cin>>h>>m>>s;
	cout<<"Reset and Show object c1:";
	c1.Set(h,m,s);
	c1.Show();
	cin>>h>>m>>s;
	cout<<"Reset and Show object c2:";
	c2.Set(h,m,s);
	c2.Show();
	return 0;
}
