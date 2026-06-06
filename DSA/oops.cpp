#include<iostream>
#include<string>
using namespace std;

// class Teacher{
//     // properties/attributes 
// private:
//     double salary;
// public :
//     string name;
//     string subject;
//     string dep;

//     // Non-parametrized constructor
//     Teacher(){
//         cout << "custom constructor called" << endl;
//         dep = "Mechanical";  // default value set
//     }

//     // methods/member functions
//     void changeDepartment(string department){
//         dep = department;
//     }

//     // setter - used to set private variable
//     void setSalary(double s){
//         salary = s;
//     }

//     // getter = used to get private salary
//     double getSalary(){
//         return salary;
//     }
// };

// // Encapsulation
// class Account {
// private :
// // data hiding 
//     double balance;
//     string password; 
// public :
//     string accountId;
//     string username;
// };

// class Teacher{
//     // properties/attributes 
// private:
//     double salary;
// public :
//     string name;
//     string subject;
//     string dep;

//     // Non-parametrized constructor
//     Teacher(){
//         cout << "custom constructor called" << endl;
//         dep = "Mechanical";  // default value set
//     }

//     // parametrized constructor
//     // Teacher(string n, string dept, double sal , string sub){
//     //   name = n;
//     //   dep = dept;
//     //   salary = sal;
//     //   subject = sub;
//     // }

//     Teacher(string name, string dep, double salary , string subject){
//       this->name = name;
//       this->dep = dep;
//       this->salary = salary;
//       this->subject = subject;
//     }

//     //------------------Copy Constructor
//     Teacher(Teacher &orObj){
//       this->name = orObj.name;
//       this->dep = orObj.dep;
//       this->salary = orObj.salary;
//       this->subject = orObj.subject;
//     }
//     // methods/member functions
//     void getInfo(){
//         cout << "Name : " << name << endl;
//         cout << "Subject : " << subject << endl;
//         cout << "Department : " << dep << endl;
//         cout << "Salary : " << salary << endl;
//     }
// };

//--------------Shallow and Deep copy
// class Student{
// public :
//     string name;
//     // double cgpa;
//     double *cgpaPtr; // not pointing anywhere

//     Student(string name, double cgpa){
//         this->name = name;
//         // this->cgpa = cgpa;
//         cgpaPtr = new double;  //pointing to this loc
//         *cgpaPtr = cgpa;
//     }

//     // Shallow copy
//     Student(Student &obj){
//         this->name = obj.name;
//         // this->cgpa = obj.cgpa;
//         this->cgpaPtr = obj.cgpaPtr;
//     }

//     // Deep Copy
//     // Student(Student &obj){
//     //     this->name = obj.name;
//     //     // this->cgpa = obj.cgpa;
//     //     // this->cgpaPtr = obj.cgpaPtr;
//     //     cgpaPtr = new double;  //pointing to this loc
//     //     *cgpaPtr = *obj.cgpaPtr;
//     // }

//     void getInfo(){
//         cout << "Name : " << name << endl;
//         // cout << "CGPA : " << cgpa << endl;
//         cout << "CGPA : " << *cgpaPtr << endl;
//     }

//     ~Student(){
//         cout << "Hi, I delete everything!";
//         delete cgpaPtr; // If we don't do this, then it causes memory leak
//     }
// };

// -----------------------Inheritance
// // Single-level Inheritance
// class Person {
// public :
//     string name;
//     int age;

//     // Person(){
//     //     cout << "Parent constructor called!" << endl;
//     // }
//     Person(string name,int age){
//         this->name = name;
//         this->age = age;
//     }
// };

// class Student : public Person {
// public :
//     int rollNo;

//     // Student(){
//     //     cout << "Child constructor called!" << endl;
//     // }

//     Student(string name, int age, int rollNo) : Person(name,age){
//        this->rollNo = rollNo;
//     }

//     void getInfo(){
//         cout << "Name : " << name << endl;
//         cout << "Age : " << age << endl;
//         cout << "Roll no. : " << rollNo << endl;

//     }
// };

// // Multi-level Inheritance
// class Person {
// public :
//     string name;
//     int age;

//     // Person(){
//     //     cout << "Parent constructor called!" << endl;
//     // }
//     Person(string name,int age){
//         this->name = name;
//         this->age = age;
//     }
// };

// class Student : public Person {
// public :
//     int rollNo;

//     // Student(){
//     //     cout << "Child constructor called!" << endl;
//     // }

//     Student(string name, int age, int rollNo) : Person(name,age){
//        this->rollNo = rollNo;
//     }

//     void getInfo(){
//         cout << "Name : " << name << endl;
//         cout << "Age : " << age << endl;
//         cout << "Roll no. : " << rollNo << endl;

//     }
// };

// class GraduateStudent : public Student{
// public:
//     string subject;
//     double salary;
//     GraduateStudent(string name, int age, int rollNo,string subject,double salary) : Student(name,age,rollNo){
//         this->subject = subject;
//         this->salary = salary;
//     }
// };

// Multiple Inheritance
// class Person {
// public :
//     string name;
//     int age;
// };

// class Student  {
// public :
//     int rollNo;
// };

// class GraduateStudent : public Student, public Person{

// };

// Hierarchial Inheritance
// class Person {
// public :
//     string name;
//     int age;
// };

// class Student : public Person  {
// public :
//     int rollNo;
// };

// class Teacher : public :Person{
//     public : 
//     string subject;
// };

// --------------Polymorphism
// class Student {
// public :
//     string name;
//     // Constructor Overloading
//     Student(){
//         cout << "Non-parametrized constructor" << endl;
//     }
//     Student(string name){
//         cout << "Parametrized constructor" << endl;
//         this->name = name;
//     }

//     // function Overloading
//     void getInfo(){
//         cout << "Your name is : " << name << endl;
//     }

//     void getInfo(string name){
//         cout << "Your given name is : " << name << endl;
//     }

// };

// class Child : public Student {
// public :
//     int age;
//     Child(string name, int age) : Student(name){
//         this->age = age;
//     }
//     // function overriding
//     void getInfo(){
//         cout << "Your name is : " << name << " and age is : " << age << endl;
//     }
// };

// Virtual Functions - Run Time polymorphism
// class Parent {
//     public :
//         void getInfo(){
//             cout << "parent class" << endl;
//         }
//         virtual void hello(){
//             cout << "hello from parent class" << endl;
//         }
// };

// class Child{
//     public :
//         void getInfo(){
//             cout << "child class" << endl;
//         }
//         void hello(){
//             cout << "hello from child class" << endl;
//         }
// };

// Abstract Classes
// class Shape {
//     virtual void draw() = 0; // pure virtual function
// };

// class Circle {
//     public : 
//         void draw(){
//             cout << "Drawing a circle ...." << endl;
//         }
// };

//-------------------Static keyword
// static variables
// void func(){
//     // int x = 0;
//     static int x = 0;
//     cout << "x : " << x <<endl;
//     x++;
// }

// class A {
//     public :
//          int x;

//         void incX(){
//             x = x+1;
//         }
// };

// Static objects
class ABC {
    public :
    ABC(){
        cout << "Constructor called!" << endl;
    }
    ~ABC(){
         cout << "Deconstructor called!" << endl;
    }
};

int main(){
    // ---------------------Non-parametrized constructor
    // Teacher t1;  // default constructore called
    // t1.name = "Kajal";
    // t1.subject = "Computer";
    // t1.setSalary(25000);
    // // t1.dep = "Research and development";

    // cout << t1.name << endl;
    // cout << t1.subject << endl;
    // cout << t1.getSalary() << endl;
    // cout << t1.dep << endl;
    // t1.changeDepartment("Computer Science");
    // cout << t1.dep << endl;

    // ---------------------Parametrized constructor
    // Teacher t2("Kajal","computer science",30000,"c++");
    // cout << t2.name << endl;
    // cout << t2.subject << endl;
    // cout << t2.dep << endl;
    // t2.getInfo();

    // ---------------Copy Constructor - when not created constructor in class then calls default copy constructor
    // Teacher t3(t2);
    // cout << t3.name << endl;
    // t3.dep = "civil";
    // cout << t3.dep << endl;

    // -------------------Shallow and Deep Copy
    // Student s1("Rahul Kumar" ,9.2);
    // s1.getInfo();
    // Student s2(s1);
    // *(s2.cgpaPtr) = 8.9;
    // // change both obj cgpa because of dynamic memory allocation, this is example of shallow copy
    // s2.getInfo();
    // s1.getInfo();

    // -----------------------------Inheritance
    // ----Single-level Inheritance
    // Student s1;
    // s1.name = "Kajal";
    // s1.age = 24;
    // s1.rollNo = 159;
    // s1.getInfo();

    // Student s1("Kajal",34,23);
    // s1.getInfo();

    // -----Multilevel Inheritance
    // GraduateStudent gs("Kajal", 24, 89, "computer", 30000);
    // gs.getInfo();

    // -----Multiple Inheritance
    // GraduateStudent gs;
    // gs.name = "Kumari";
    // gs.rollNo = 34;
    // gs.age = 23;
    
    // cout << gs.name << endl;
    // cout << gs.age << endl;
    // cout << gs.rollNo << endl;

    // ---------Hierarchial Inheritance
    // Teacher t1;
    // t1.name = "Kumari";
    // t1.rollNo = 34;
    // t1.age = 23;
    
    // t1 << gs.name << endl;
    // t1 << gs.age << endl;
    // t1 << gs.rollNo << endl;
    
    // -----------------Polymorphism
    // Overloading- Compile time
    // Student s1;
    // s1.name = "Kajal Kumari";
    // cout << s1.name << endl;
    // s1.getInfo();

    // Student s2("Tiwari");
    // cout << s2.name << endl;
    // s2.getInfo("Tiwari");

    // OverRiding - Run time
    // Child ch("Child1",12);
    // ch.name = "Child1";
    // ch.age = 12;
    // ch.getInfo();

    // virtual function
    // Parent p1;
    // p1.hello();
    // Child ch2;
    // ch2.hello();

    // -----Abstraction using abstract classes
    // Circle c1;
    // c1.draw();

    //-------------------Static keyword
    // if int x = 0 , returns all time 0 but when we declare with static then in returns 0,1,2,3
    // func();
    // func();
    // func();
    // func();  

    // For 2 objects it creates x two different places, but when we create using static then only one place x will be create
    // Static variables
    // A obj;
    // A obj2;
    // obj.x = 0;
    // obj2.x = 0;
    // cout << obj.x << endl;
    // cout << obj2.x << endl;
    // obj.incX();
    // obj2.incX();
    // cout << obj.x << endl;
    // cout << obj2.x << endl;

    // Static Objects
    if(true){
        // ABC abc;
        static ABC abc;
    }
    cout << "out of main func!" << endl;
   
    return 0;
}