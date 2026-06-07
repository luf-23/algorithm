#include<iostream>
#include<cstring>
using namespace std;

//你提交的代码在这里
class Student{
private:
	int ID;
	string NAME;
	int SCORE;
public:
	Student(int id=10000,string name="NULL",int score=0);
	int GetId() {return ID;}
	string GetName() {return NAME;}
	int GetScore() {return SCORE;}
	void Show();
	void Set(int id,string name,int score);
	void Set();
};
Student::Student(int id,string name,int score){
	ID = id;
	NAME = name;
	SCORE = score;
}
void Student::Show(){
	cout << ID << '-' << NAME << '-' << SCORE << '\n';
}
void Student::Set(int id,string name,int score){
	ID = id;
	NAME = name;
	SCORE = score;
}
void Student::Set(){
	ID = 99999;
	NAME = "NONAME";
	SCORE = 100;
}
int main()
{
	Student stu1;
	cout<<"Show object stu1:";
	cout<<stu1.GetId()<<"-"<<stu1.GetName()<<"-"<<stu1.GetScore()<<endl;
	int no,s;
	char xm[9];
	cin>>no>>xm>>s;
	Student stu2(no,xm,s);
	cout<<"Show object stu2:";
	cout<<stu2.GetId()<<"-"<<stu2.GetName()<<"-"<<stu2.GetScore()<<endl;
	cin>>no>>xm>>s;
	cout<<"Reset and Show object stu1:";
	stu1.Set(no,xm,s);
	stu1.Show();
	cout<<"Reset and Show object stu2:";
	stu2.Set();
	stu2.Show();
	return 0;
}
