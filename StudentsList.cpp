#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

class Student {
private:
	string name;
	int age;
public:
	Student(string name, int age) {
		this->name = name;
		this->age = age;
	}
	string getname() {
		return name;
	}
	int getage() {
		return age;
	}
};

bool operator<(Student& s1, Student& s2) {
	int comp = (s1.getname()).compare(s2.getname());
	if (comp > 0) return false;
	if (comp < 0) return true;
	if (s1.getage() < s2.getage()) return true;
	if (s1.getage() > s2.getage()) return false;
	return false;
}

class AllStudents :public Student {
private:
	vector<Student> s;
public:
	AllStudents() :Student("", 0) {
		s = {};
	}

	void addstudent(Student* s) {
		(this->s).push_back(*s);
	}

	void sortlistbyname() {
		sort(s.begin(), s.end());
	}
	void printlist() {
		int n = s.size();
		for (int i = 0; i < n; i++)
			cout << s[i].getname() << " " << s[i].getage() << endl;
	}
};

void main() {
	int n, age;
	string name;
	cout << "Enter no of students ";
	cin >> n;
	cout << "Enter their names and ages separated by space" << endl;
	AllStudents all;
	for (int i = 0; i < n; i++) {
		cin >> name >> age;
		Student s(name, age);
		all.addstudent(&s);
	}
	all.sortlistbyname();
	all.printlist();
}