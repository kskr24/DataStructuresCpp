#include<iostream>
using namespace std;

class Student {
public:
	//non delegating constructor
	Student(const int& roll_, const string& name_, const int& age_, const string& dept_) :
		roll(roll_),name(name_),age(age_),dept(dept_){}
	//delegating constructors
	Student():Student(0,"",0,""){}
	
private:
	int roll;
	string name;
	int age;
	string dept;



	friend ostream& operator<<(ostream& os, const Student& s);

	
};

ostream& operator<<(ostream& os, const Student& s) {
	os <<"Roll: "<<s.roll<<"\nName: "<<s.name<<"\nAge: "<<s.age<<"\nDepartment: "<<s.dept;
	return os;
}

int main() {
	Student s1(1,"Rahul",22,"CHP");
	Student s2;
	cout << s2;
	return 0;
}
