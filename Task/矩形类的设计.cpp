#include<iostream>
using namespace std;

//你提交的代码在这里
class Rectangle{
private:
	double W,H;
public:
	Rectangle(double w=2,double h=2) {W=w,H=h;}
	double GetWidth() {return W;}
	double GetHeight() {return H;}
	double Perimeter() {return 2*H+2*W;}
	double Area() {return W*H;}
	void Set(double w,double h) {W=w,H=h;}
};
int main()
{
	Rectangle rect1;
	cout<<"Show object rect1:"<<endl;
	cout<<"    width="<<rect1.GetWidth()<<endl;
	cout<<"    height="<<rect1.GetHeight()<<endl;
	cout<<"    Perimeter="<<rect1.Perimeter()<<endl;
	cout<<"    Area="<<rect1.Area()<<endl;
	double w,h;
	cin>>w>>h;
	Rectangle rect2(w,h);
	cout<<"Show object rect2:"<<endl;
	cout<<"    width="<<rect2.GetWidth()<<endl;
	cout<<"    height="<<rect2.GetHeight()<<endl;
	cout<<"    Perimeter="<<rect2.Perimeter()<<endl;
	cout<<"    Area="<<rect2.Area()<<endl;
	cin>>w>>h;
	cout<<"Reset and Show object rect1:"<<endl;
	rect1.Set(w,h);
	cout<<"    width="<<rect1.GetWidth()<<endl;
	cout<<"    height="<<rect1.GetHeight()<<endl;
	cout<<"    Perimeter="<<rect1.Perimeter()<<endl;
	cout<<"    Area="<<rect1.Area()<<endl;
	return 0;
}
