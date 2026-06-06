#include<iostream>
using namespace std;

int main(){
    // ----character arrays
    // char ch[] = {'a','b','c','\0'};  // if we not add \0 then it's not a valid string
    // cout << ch << endl;  // return abc

    // char str[] = "hello";
    // cout << str << endl;
    // cout << str[3] << endl;

    // char st[100];
    // cout << "character array : " ;
    // cin >> st;   // when we take input using cin then it ignores after space only first string will be stored
    // cin.getline(st,100);  // it store with space string syntax is : cin.getline(str,len,delimator) -delimator means where we stop string
    // cin.getline(st,50,',');   // if we write , in input , aftre , string will be ignored
    // cout << "output :" <<st ;

    // char str[12];
    // cout << "Enter character array : " ;
    // cin.getline(str,12);

    // //print all characters that talen from input
    // for(char ch : str){
    //     cout << ch << " ";
    // }

    // count string length
    // char str[] = "apna college kajal";
    // int len=0;
    // for(int i=0; i<str[i] != '\0';i++){
    //     len++;
    // }
    // cout << len << endl;

    // -------------strings
    // string are here class, we decalare variable with class string and in double quotes
    // string str = "kajal kumari";
    // cout << str << endl;

    // str = "hello";
    // cout << str << endl;  // It returens hello, but in character we can't change, there is fixed size of array

    // string str1 = "apna";
    // string str2 = "college";
    // It also supports +, comaprison opeartor
    // string str3 = str1 +" " + str2;

    // cout << str3 << endl;
    // cout << (str1==str2) << endl;
    // cout << (str1<=str2) << endl;
    // cout << str3.length() << endl;

    // string str;
    // cin >> str;   // It als0 ignore after white spaces so we can use getline(cin,str)
    // getline(cin,str);
    // cout << "output : " << str << endl;

    // looops on string
    string str;
    getline(cin,str);
    // for(int i=0;i<str.length();i++){
    //     cout << str[i] << " ";
    // }
    
    for(char ch : str){
        cout << ch << " ";
    }
    return 0;
}