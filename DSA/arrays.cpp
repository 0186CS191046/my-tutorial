#include <iostream>
using namespace std;

void changeArray(int arr[],int size){
    for(int i=0;i<size;i++){
        arr[i] = arr[i]*2;
    }
}

int linearSearch(int arr[],int size,int target){
    for(int i=0;i<size;i++){
        if(arr[i] == target){    // found
            return i;
        }
    }
    return -1;
}

void reverseArray(int arr[],int size){
    int i=0,j=size-1;
    while(i<j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

int addValues(int arr[],int size){
    int sum = 0;
     for(int i=0;i<size;i++){
        sum += arr[i];
    }
    return sum;
}

int productValues(int arr[],int size){
    int product = 1;
     for(int i=0;i<size;i++){
        product *= arr[i];
    }
    return product;
}

void swapMinMax(int arr[],int size){
    int mini = INT_MAX,maxi = INT_MIN;

    for(int i=0;i<size;i++){
       mini = min(mini,arr[i]);
       maxi = max(maxi,arr[i]);
    }

    for(int i=0;i<size;i++){
      if(arr[i] == mini){
        arr[i] = maxi;
      } 
      else if(arr[i] == maxi){
        arr[i] = mini;
      }
    }
}

void uniqueValues(int arr[],int size){
    for(int i=0;i<size;i++){
        int count = 1;
        for(int j=0;j<size;j++){
            // cout << arr[i]<< "-" << arr[j] <<endl;
            if(i!=j){
                if(arr[i]== arr[j]){
                    count ++;
                }
            }
           
        }
        if(count==1){
            cout << "unique values :" <<  arr[i] <<endl;
        }
    }
}

void printIntersection(int arr1[],int arr2[],int size1,int size2){

    for(int i=0;i<size1;i++){
        for(int j=0;j<size2;j++){
            if(arr1[i]==arr2[j]){
                cout<<arr1[i]<<endl;
                break;
            }
        }
    }
}

int main(){

    // --------------- Array Creation----------------
    // int marks[10];   //syntax for declaring empty array of size 10
    // double price[50];

    // int marks[5] = {34,56,78,32,99};   //syntax for declaring array of size 5
    // double price[] = {78,34,67,89,80};  // can also write like this

    // cout << marks[0] << endl;  // array can be access directly using indexes
    // cout << marks[1] << endl;
    // cout << marks[2] << endl;
    // cout << marks[3] << endl;
    // cout << marks[4] << endl;

    // marks[0] = 100;
    // cout << marks[0] << endl;  // It changes the value of index 0.

    // ------------Loops in Array-----------------
    // int marks[5] = {34,56,78,32,99};   
    // int size = 5;

    // cout << sizeof(marks) <<endl;  // It returns bytes used in array
    // cout << (sizeof(marks)/sizeof(int)) <<endl;  // return the size of the array

    // // print the array values
    // for(int i=0;i<size;i++){
    //     cout << marks[i] <<endl;
    // }

    // take array values from input;
    // int size = 5;
    // int marks[size];

    // for(int i=0;i<size;i++){
    //     cin >> marks[i] ;
    // }
    // cout <<"Array values are :" ;
    // for(int i=0;i<size;i++){
    //     cout << marks[i] <<" " ;
    // }

    // ----------find smallest/largest in array
    // int mini = INT_MAX;
    // int maxi = INT_MIN;
    // int size = 5;

    // int marks[] = {34,56,78,32,99};   
    // for(int i=0;i<size;i++){
    //    if(marks[i]<mini){
    //     mini = marks[i];
    //    }
    //    if(marks[i]>maxi){
    //     maxi = marks[i];
    //    }
    // mini = min(mini,marks[i]);
    // maxi = max(maxi,marks[i]);
    // }

    // cout << "Largest is :" << maxi << endl;
    // cout << "Minimum is :" << mini << endl;
    
    // ---------------Pass by reference--------------------
    // int marks[] = {34,56,78,32,99}; 
    // changeArray(marks,5);

    // cout <<"After changeArray function :" <<endl; 
    // for(int i=0;i<5;i++){
    //     cout << marks[i] <<" " ;
    // }

    // -----------------Linear Search--------------------------
    // int arr[] = {2,4,7,8,9,3,5},size = 7;
    // int target = 5;

    // cout << linearSearch(arr,size, target);

    // -----------------Reverse an array------------
    // int arr[] = {2,4,7,8,9,3,5},size = 7;

    // reverseArray(arr,size);
    // for(int i=0;i<size;i++){
    //     cout << arr[i] <<" " ;
    // }
    // return 0;

    // --------Write a function for sum and product of all numbers in an array
    //     int arr[] = {2,4,7,8,9,3,5},size = 7;

    //    cout << "Sum is : " <<addValues(arr,size) <<endl;
    //    cout << "Product is : " << productValues(arr,size) <<endl;

    // -----------swap min and max----------------
    // int arr[] = {2,4,7,8,9,3,5},size = 7;;
    // swapMinMax(arr,size);
    // for(int i=0;i<size;i++){
    //     cout << arr[i] <<endl;
    // }

    // -------------Write a function to print all unique values
    // int arr[] = {2,4,7,8,4,7,8,5},size = 8;;
    // uniqueValues(arr,size);

    // ------------Write a function to print intersection of 2 arrays
    int arr1[] = {2,4,7,8,4,7,8,5}, arr2[] = {2,4,7,8,5}, size = 8;
    cout << (arr1,arr2,sizeof(arr1)/sizeof(int))<<endl;
    printIntersection(arr1,arr2,sizeof(arr1)/sizeof(int),sizeof(arr2)/sizeof(int));

}