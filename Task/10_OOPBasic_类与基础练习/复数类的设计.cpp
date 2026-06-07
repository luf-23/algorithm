#include<iostream>
using namespace std;

//你提交的代码在这里
class Complex{
private:
	double R,I;
public:
	Complex(double r=1,double i=2) {R=r,I=i;}
	void Show();
	void Set(double r,double i) {R=r,I=i;}
};
void Complex::Show(){
	if (R!=0) cout << R;
	if (I!=0){
		if (I>0) cout << "+";
		cout << I << "i\n";
	}
	if (R==0&&I==0) cout << 0 << '\n';
}
int main()
{
	Complex c1;
	cout<<"Show object c1:";
	c1.Show();
	double real,imag;
	cin>>real>>imag;
	Complex c2(real,imag);
	cout<<"Show object c2:";
	c2.Show();
	cin>>real>>imag;
	cout<<"Reset and Show object c1:";
	c1.Set(real,imag);
	c1.Show();
	return 0;
}
