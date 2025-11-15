#include <bits/stdc++.h>

using namespace std;

class Student{
    private:
        string name;
        int age;
    public:
        void getInformation(string name,int age){
            this-> name = name;
            this-> age = age;
        }

        void display(){
            cout << name << endl;
            cout << age << endl;
        }  
};

int main(){
    string name; int age;

    cin >> name >> age;

    Student s1;
    Student s2;

    s1.getInformation(name,age);
    s1.display();

    s2.getInformation("phuc", 18);
    s2.display();

    return 0;
}