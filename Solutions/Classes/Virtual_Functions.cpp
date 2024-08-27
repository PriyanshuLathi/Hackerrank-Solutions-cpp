#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person{
public:
    string name;
    int age;
    virtual void getdata() = 0;
    virtual void putdata() = 0;
};

class Professor: public Person{
private:
    int publications;
    int cur_id;
    static int id;
public:
    Professor() {
        cur_id= ++id;
    }
    virtual void getdata() override{
        cin >> name >> age >> publications;
    }
    virtual void putdata() override{
        cout << name << " " << age << " " << publications << " " << cur_id << endl;
    }
};

int Professor::id = 0;

class Student: public Person{
private:
    int marks[6];
    int cur_id;
    static int id;
    int sum = 0;
public:
    Student(){
        cur_id= ++id;
    }
    virtual void getdata() override{
        cin >> name >> age;
        for(int i=0; i<6; i++){
            cin >> marks[i];
        }
    }
    virtual void putdata() override{
        for(int i=0; i<6; i++){
            sum += marks[i];
        }
        cout << name << " " << age << " " << sum << " " << cur_id << endl; 
    }
};

int Student::id = 0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
