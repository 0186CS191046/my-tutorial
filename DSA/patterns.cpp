#include <iostream>
using namespace std;

int main(){
    // -----------square pattern
        // 1 2 3 4
        // 1 2 3 4
        // 1 2 3 4
        // 1 2 3 4
    int n;
    cout << "Enter number : ";
    cin >> n;

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout << j << " ";
    //         // cout << "*" << " ";
    //     }
    //     cout << endl;
    // }

    // ----------square pattern
        // * * * *
        // * * * *
        // * * * *
        // * * * *

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout << "*" << " ";
    //     }
    //     cout << endl;
    // }

    //  -------- square pattern
    //     // A B C D
    //     // A B C D
    //     // A B C D
    //     // A B C D

    // for(int i=1;i<=n;i++){
    //     char ch = 'A';
    //     for(int j=0;j<n;j++){
    //         cout << ch <<" ";
    //         ch+=1;
    //     }
    //     cout << endl;
    // }

    // ---------------square pattern
        // 1 2 3
        // 4 5 6
        // 7 8 9
    // int num = 1;
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<n;j++){
    //         cout << num <<" ";
    //         num+=1;
    //     }
    //     cout << endl;
    // }
    // cout << "after pattern :" <<num;

    // // ----------------square pattern
    //     // A B C
    //     // D E F
    //     // G H I

    // char ch = 'A';
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<n;j++){
    //         cout << ch <<" ";
    //         ch+=1;
    //     }
    //     cout << endl;
    // }
    // cout << "after pattern :" <<ch;

    // ----------------Triangle pattern-easy with stars
        // *
        // * *
        // * * *

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<i+1;j++){
    //         cout << "* " ;
    //     }
    //     cout << endl;
    // }

    // ----------------Triangle pattern-easy with number
        // 1
        // 2 2
        // 3 3 3

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<i+1;j++){
    //         cout << i+1 <<" ";
    //     }
    //     cout << endl;
    // }

    // ----------------Reverse Triangle pattern- with numbers
        // 1
        // 2 1
        // 3 2 1

    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j>0;j--){
    //         cout << (j) <<" ";
    //     }
    //     cout << endl;
    // }

    // ----------------Reverse Triangle pattern- with characters
        // A
        // B A
        // C B A
    // for(int i=0;i<n;i++){
    //     char ch = 'A';
    //     for(int j=i;j>=0;j--){
    //         char ch1 = ch + j ;
    //         cout << ch1 <<" ";
    //     }
    //     cout << endl;
    // }

     // ---------------- Floyd's Triangle pattern- with numbers
        // 1
        // 2 3
        // 4 5 6

    // int num = 1;
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j>0;j--){
    //         cout << num <<" ";
    //         num++;
    //     }
    //     cout << endl;
    // }
    
    // ----------------Floyd's Triangle pattern- with characters
        // A
        // B C
        // D E F
    
    // char ch = 'A';
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j>0;j--){
    //         cout << ch <<" ";
    //         ch++;
    //     }
    //     cout << endl;
    // }

    // ----------------Inverted Triangle pattern - reverse numbers
        // 1 1 1
        //   2 2
        //     3

    // for(int i=0;i<n;i++){
    //     for(int j=i;j>0;j--){
    //         cout <<" ";
    //     }
    //     for(int j=n;j>i;j--){
    //         cout << i+1 ;
    //     }
    //     cout << endl;
    // }

    // ----------------Inverted Triangle pattern - reverse characters
        // A A A
        //   B B
        //     C
    // char ch = 'A';
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<i;j++){
    //         cout <<" ";
    //     }
    //     for(int j=0;j<n-i;j++){
    //         cout << ch ;
    //     }
    //     ch++;
    //     cout << endl;
    // }

    // ----------------Pyramid Pattern -  numbers
        //    1
        //   121
        //  12321

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n-i-1;j++){
    //         cout <<" ";
    //     }
    //     for(int j=0;j<i+1;j++){
    //         cout << j+1 ;
    //     }
    //     for(int j=i;j>=1;j--){
    //         cout << j;
    //     }
    //     cout << endl;
    // }

    // hollow pattern or diamon problem--------------
        //        *
        //     *     *
        //  *           *
        //     *      *
        //         *     
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<=n-1;j++){
    //         cout << " " ;
    //     }

    //     cout <<"*" ;
    //     if(i!=0){
    //         for(int k=0;k<(2*i-1);k++){
    //             cout << " " ;
    //         }
    //         cout << "*";
    //     }
    //    cout << endl;
    // }

    // for(int i=n-1;i>0;i--){
    //     for(int j=0;j<n-i;j++){
    //         cout << " " ;
    //     }

    //     cout <<"*" ;
    //     if(i>1){
    //         for(int k=0;k<(2*(i-1)-1);k++){
    //             cout << " " ;
    //         }
    //         cout << "*";
    //     }
    //    cout << endl;
    //}

    // ---------------butterfly pattern
        // *       *
        // * *   * *
        // * * * * *
        // * * * * *
        // * *   * *
        // *       *

    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cout << "*";
        }
        for(int k=0;k<2*(n-i-1);k++){
            cout << " " ;
        }
        for(int l =0;l<i+1;l++){
            cout << "*";
        }
        cout <<endl;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout << "*";
        }
        for(int k=0;k<2*i;k++){
            cout << " " ;
        }
        for(int l =0;l<n-i;l++){
            cout << "*";
        }
        cout <<endl;
    }
    


}