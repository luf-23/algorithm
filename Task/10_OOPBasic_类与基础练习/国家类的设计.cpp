#include<iostream>
#include<cstring>
using namespace std;

//你提交的代码在这里
class Country{
private:
	string name,sd;
	int cnt;
public:
	Country(string n="NULL",string c="NONE",int count=0){
		name = n;
		sd = c;
		cnt = count;
	}
	string GetName() {return name;}
	string GetCapital() {return sd;}
	int GetPopulation() {return cnt;}
	void Show(){
		cout << name << '-' << sd << '-' << cnt << '\n';
	}
	void Set(string n="China",string s="Beijing",int count=1400000000){
		name = n;
		sd = s;
		cnt = count;
	}
};
int main()
{
	Country c1;
	cout<<"Show object c1:";
	cout<<c1.GetName()<<"-"<<c1.GetCapital()<<"-"<<c1.GetPopulation()<<endl;
	char name[40],capital[40];
	int population;
	cin>>name>>capital>>population;
	Country c2(name,capital,population);
	cout<<"Show object c2:";
	cout<<c2.GetName()<<"-"<<c2.GetCapital()<<"-"<<c2.GetPopulation()<<endl;
	cin>>name>>capital>>population;
	cout<<"Reset and Show object c1:";
	c1.Set(name,capital,population);
	c1.Show();
	cout<<"Reset and Show object c2:";
	c2.Set();
	c2.Show();
	return 0;
}
