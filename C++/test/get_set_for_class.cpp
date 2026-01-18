#include<iostream>
using namespace std;
class Employee {
private:
	int id;
	string firstName;
	string lastName;
	int salary;

public:
	Employee(int id, string firstName, string lastName, int salary) {
		this->id = id;
		this->firstName = firstName;
		this->lastName = lastName;
		this->salary = salary;
	}

	int getId() {
		return id;
	}

	void setId(int id) {
		this->id = id;
	}

	string getFirstName() {
		return firstName;
	}

	void setFirstName(string firstName) {
		this->firstName = firstName;
	}

	string getLastName() {
		return lastName;
	}

	void setLastName(string lastName) {
		this->lastName = lastName;
	}

	string getFullName() {
		return firstName + " " + lastName;
	}

	int getSalary() {
		return salary;
	}

	void setSalary(int salary) {
		this->salary = salary;
	}
};

int main(){
    int id;
	string firstName;
	string lastName;
	int salary;

    cin >> id >> firstName >> lastName >> salary;

    Employee s(id,firstName,lastName,salary);
    cout << s.getId() << endl;
    cout << s.getFirstName() << endl;
    cout << s.getLastName() << endl;
    cout << s.getSalary() << endl;

    Employee s1(1, "Phuc", "Dang", 100);
    cout << s1.getId() << endl;
    cout << s1.getFirstName() << endl;
    cout << s1.getLastName() << endl;
    cout << s1.getSalary() << endl;

    return 0;
}