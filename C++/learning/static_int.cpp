#include <bits/stdc++.h>

using namespace std;

class Student {
    private:
        string name;
        char gender;
    public:
        Student(string name = "Unknown", char gender = 'u') {
            this -> name = name;
            this -> gender = gender;
        }

        void display(){
            cout << "Name: " + name << endl;
            
            if (gender == 'u'){
                cout << "Gender: Unknown" << endl; 
            }
            if (gender == 'm'){
                cout << "Gender: Male" << endl;
            }
            if (gender == 'f'){
                cout << "Gender: Female" << endl;
            }
        }
};

int main(){
    string name;
    char gender;

    cin >> name >> gender;

    Student s1(name, gender);
    s1.display();

    Student s2("phuc",'u');
    s2.display();

    Student s3;
    s3.display();
}