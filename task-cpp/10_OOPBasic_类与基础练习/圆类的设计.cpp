#include<iostream>
using namespace std;

//你提交的代码在这里
class Circle{
private:
	double r;
public:
	Circle(double rr=10);
	double Get();
	double Square();
	double Circumference();
	void Set(double rr);
};
Circle::Circle(double rr){
	r = rr;
}
double Circle::Get(){
	return (double)r;
}
double Circle::Square(){
	return (double)3.14*r*r;
}
double Circle::Circumference(){
	return (double)2*3.14*r;
}
void Circle::Set(double rr){
	r = rr;
}

int main()
{
	Circle c1;
	cout<<"Show object c1:"<<endl;
	cout<<"    radius="<<c1.Get()<<endl;
	cout<<"    Circumference="<<c1.Circumference()<<endl;
	cout<<"    Square="<<c1.Square()<<endl;
	double r;
	cin>>r;
	Circle c2(r);
	cout<<"Show object c2:"<<endl;
	cout<<"    radius="<<c2.Get()<<endl;
	cout<<"    Circumference="<<c2.Circumference()<<endl;
	cout<<"    Square="<<c2.Square()<<endl;
	cin>>r;
	cout<<"Reset and Show object c1:"<<endl;
	c1.Set(r);
	cout<<"    radius="<<c1.Get()<<endl;
	cout<<"    Circumference="<<c1.Circumference()<<endl;
	cout<<"    Square="<<c1.Square()<<endl;
	return 0;
}
