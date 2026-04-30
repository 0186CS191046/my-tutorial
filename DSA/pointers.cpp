#include <iostream>
using namespace std;

void changeA(int a){  // pass by value
    a = 20;
}

void changeA2(int *ptr){  // pass by reference using pointers
    *ptr = 20;
}

void changeA3(int &b){  // pass by reference using aliases
    b = 20;
}

int main(){
    // ----------pointers syntax-------------
    // int a = 10;
    // int* ptr = &a;
    // cout << &a <<endl;   //It is address of a
    // cout << ptr << endl;  // It is value which stored in ptr;

    // float price = 100.60;
    // float* ptr2 = &price;

    // cout << &price << endl;
    // cout << ptr2 << endl;

    // -------------pointer to pointer----------------
    // It means it stores value of another pointer, every pointer has own address and that address stored in another value
    // int a = 45;
    // int* ptr1 = &a;
    // int ** ptr2 = &ptr1;

    // cout << a << endl;

    // cout << &a << endl;
    // cout << ptr1 << endl;

    // cout << ptr2 << endl;
    // cout << &ptr1 << endl;

    // cout << &ptr2 << endl;

    // -----------derefence operator------------
    // It means what is the value of that memory address
    // int a = 45;
    // int* ptr1 = &a;
    // int ** ptr2 = &ptr1;

    // cout << a << endl;

    // cout << *(ptr1) << endl;   // it return *(&a) -> *(0x580dbff7fc) -> 45;
    // cout << **(ptr2) << endl;  // it return *(*(&ptr1)) -> *(*(0x580dbff7f0)) -> *(0x580dbff7fc) -> 45;
    // cout << *(ptr2) << endl;   // it returns value of ptr1;

    // ------------NULL pointer-----------------
    // int **ptr = NULL;
    // cout << (ptr) << endl;
    // cout << *(ptr) << endl;  // we can't do dereference

    // int a = 5;
    // int* p = &a;
    // int ** q = &p;

    // cout << (*p) << endl;  // 5
    // cout << (**q) << endl;  // 5;
    // cout << (p) << endl;   // address of a;
    // cout << (*q) << endl;  // p value - means address of a

    // -----------pass by refernce--------------------
    // int a = 10;
    // // changeA(a);    //pass by value
    // // changeA2(&a);  //pass by reference using pointers
    // changeA3(a); //pass by refrence using aliases

    // cout << a << endl; 

    // -------------array pointers--------------
    // It is not changeable Example-
    // int a = 23;
    // int b = 24;
    // int *ptr = &a;  // In future ptr can store another variable of address but for array not allowed
    // cout << ptr << endl;

    // // -----------Arithmetic pointer------------
    // int a = 10;
    // int * ptr = &a;
    // cout << ptr << endl;
    // ptr++;   // increased by 1 bytes means 4 bits becuse it's integer type
    // cout << ptr << endl;
    // ptr--;   // decreased by 1 bytes means 4 bits becuse it's integer type
    // cout << ptr << endl;
    // ptr = ptr +2;   // increased by 2 bytes means 8 bits becuse it's integer type
    // cout << ptr << endl;
    // ptr = ptr - 2; // decreased by 2 bytes means 8 bits becuse it's integer type
    // cout << ptr << endl;

    // int arr[] = {1,2,3,4,5};

    // cout << arr << endl;   // It return address of arr
    // cout << *arr << endl;  // It return value of 0th index of arr
    // cout << *(arr+1) << endl;
    // cout << *(arr+2) << endl;
    // cout << *(arr+3) << endl;
    // cout << *(arr+4) << endl;

    // ------------Arithmetic between two pointers----------
    // int * ptr;  // 100   don't run this code
    // int * ptr2 = ptr + 2; //108
    // cout << (ptr2-ptr) << endl;  // 2

    // int * ptr ; 
    // int * ptr2 ;
    // cout << (ptr2<ptr) << endl;  
    // cout << (ptr2>ptr) << endl;  
    // cout << (ptr2!=ptr) << endl;  

    int arr[] = {10,20,30,40};
    int *ptr = arr;

    cout << *(ptr+1) << endl;  // 20
    cout << *(ptr+3) << endl;  // 40
    ptr++;
    cout << *ptr << endl;      // 20
    return 0;
}