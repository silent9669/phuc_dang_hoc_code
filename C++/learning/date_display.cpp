#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

class Date{
    private:
        int day;
        int month;
        int year;
    public:
        Date(int day, int month, int year){
            this -> day = day;
            this -> month = month;
            this -> year = year;
        }

        void setDate(int day, int month, int year){
            this -> day = day;
            this -> month = month;
            this -> year = year; 
        }

        void setDay(int day){
            this -> day = day;
        }

        void setMonth(int month){
            this -> month = month;
        }

        void setYear(int year){
            this -> year = year;
        }

        int getDay(){
            return day;
        }
        
        int getMonth(){
            return month;
        }

        int getYear(){
            return year;
        }

        void display(){
            cout << setfill('0') << setw(2) << day << "/" 
                 << setfill('0') << setw(2) << month << "/" ;
            cout << year << endl;
        }
};

int main(){
    int day;
    int month;
    int year;

    cin >> day >> month >> year;

    Date s(day, month, year);
    s.display();

    Date s1(21,9,2007);
    s1.display();

    return 0;
}