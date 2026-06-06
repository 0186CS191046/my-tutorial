#include <iostream>
#include <vector>  // for vector stl
#include <list>    // for list stl
#include <deque>   // for deque
#include <stack>   // for stack
#include <queue>   // for queue
#include <map>     // for map
#include <unordered_map> // for unordered_map
#include <set>     // for set
#include <unordered_set>  // for unordered_set
#include <algorithm>
using namespace std;

bool comparator(pair<int,int>p1, pair<int,int>p2){  // sort on the basis of 2nd value
    if(p1.second<p2.second) return true;
    else return false;
}

bool comparator2(pair<int,int>p1, pair<int,int>p2){  // sort on the basis of 1st value if 2nd value is same
    if(p1.second<p2.second) return true;
    if(p1.second>p2.second) return false;

    if(p1.first < p2.first) return true;
    else return false;
}

int main(){

    // --------------------Vector----------------------------
    // vector<int> vec;  //empty vector

    // cout << vec.size() <<endl;  // return length
    // cout << vec.capacity() <<endl;  // return capacity

    // vec.push_back(1);
    // vec.push_back(2);
    // vec.push_back(3);   // push_back works in O(1) time complexity
  
    // vec.pop_back();
    // vec.emplace_back(5);

    // cout << vec.size() <<endl; 
    // cout << vec.capacity() <<endl;
    
    // cout << vec.at(2) <<endl;  // return value at index also we can write vec[2]
    // cout << vec[2] <<endl;

    // cout << vec.front() <<endl;  // return value at index 0
    // cout << vec.back() <<endl;  // return value at last index

    // for(int val:vec){
    //     cout << "value--" << val << endl;
    // }
    
    // vector<int> vec = {1,2}  // with 2 length
    // vector<int> vec(2,1);  // 2 times 1
    // vector<int> vec2(vec);    // It takes value from vec
    // for(int val:vec){
    //     cout << "value--" << val << endl;
    // }

    // vector<int> vec = {1,2,4,5,6};  // with 5 length
    // vec.erase(vec.begin());   // It takes O(n) time complexity, erase and clear It only changes size but not capacity
    // vec.erase(vec.begin()+2); 
    // vec.erase(vec.begin()+1,vec.end()); 
    // vec.insert(vec.begin()+2,8);   //It inserts 8 at position 2

    // for(int val:vec){
    //     cout << "value--" << val << endl;
    // }
    // vec.clear();   // It clears the vector
    // cout << vec.size() <<endl;  
    // cout << vec.capacity() <<endl; 
    // cout << vec.empty() <<endl;         // It checks whether vector is empty or not
   

    // ------Iterators
    // vector<int> vec = {1,2,4,5,6}; 
    // cout << *(vec.begin())<<endl;  // It returns value at index 0
    // cout << *(vec.end()) << endl;  // It return -1 because vec.end() points length of vector
    // cout << *(vec.end()-1) << endl;  // It returns 6

    // vector<int>::iterator it;
    // for(it=vec.begin();it != vec.end();it++){
    //     cout << *(it) << endl;
    // }

    // --reverse iterator
    // vector<int>::reverse_iterator it;
    // for(it=vec.rbegin();it!=vec.rend();it++){
    //     cout << *(it) << endl;
    // }

    // we can also write like this
    
    // for(vector<int>::reverse_iterator it=vec.rbegin();it!=vec.rend();it++){
    //     cout << *(it) << endl;
    // }
    // for(auto it=vec.rbegin();it!=vec.rend();it++){  // instead of writing vector<int>::reverse_iterator we can write auto 
    //     cout << *(it) << endl;
    // }

    // --------------------------List----------------------

    // List is internally implemented as a doubly linked list means we can push or pop from frond your back
    // which function exists in vector that is also available in list
    // List has not possible to random access means we can use like l[2].

    // list<int> l;
    // l.emplace_back(10);
    // l.push_back(2);
    // l.push_back(4);
    // l.push_front(6);
    // l.push_front(8);
    // l.emplace_front(12);

    // for(int val : l){
    //     cout << val << " " ;
    // }
    // cout << endl;

    // l.pop_back();
    // l.pop_front();

    // for(int val : l){
    //     cout << val << " " ;
    // }

    // cout << endl;
    // cout << "size of list : " << l.size() <<endl;
    // l.erase(l.begin());
    // for(int val : l){
    //     cout << val << " " ;
    // }
    // l.clear() ;
    // cout << endl;
    // cout << "Is list empty : " << l.empty() <<endl;

    // list<int> li = {3,5,7,9};
    // list<int> :: iterator list1;  // we can also write auto instead of this declaration.
    // for(list1 = li.begin();list1 != li.end(); list1++){  
    //     cout  << *(list1) <<endl;
    // }

    // for(auto list1 = li.rbegin();list1 != li.rend(); list1++){
    //     cout  << *(list1) <<endl;
    // }

    // -----------------------------Deque(Double ended queue)------------------------
    // Internally it's implemented dynamic arrays so, here possible random access means we can use d[2], it's like list, only two difference is there
    // same function which is in list :- size, capacity, erase, insert, clear, begin , end, rbegin, rend, front, back, push_back, pop_back, push_front, pop_front, emplace_back , emplace_front
    // deque<int> d = {2,3,4,5,6,7};
    // for(int val:d){
    //     cout << val <<" " << endl;
    // }

    // ------------------Pair----------------------
    // pair<char,int> p ={'a',5};  // pair of one character type and second one is integer
    // pair<int,int> p ={3,5};   // pair of 2 integer values
    // cout << p.first << endl;   // return first value of the pair
    // cout << p.second << endl;  // return second value of the pair

    // pair <char,pair<char, int>> p = {'a',{'b', 5}};   // This is pair of pair
    // cout << p.first << endl;   // return a
    // cout << p.second.first << endl;  // return b
    //  cout << p.second.second << endl;  // return b

    // -----pairs inside vector
    // vector <pair <int, char>> vec = {{1,'a'},{2,'b'},{3,'c'}};
    // for(pair <int ,char> p : vec){
    //     cout << p.first << "-" << p.second << endl;
    // }
    
    // cout  << endl;
    
    // vec.push_back({4,'d'});  // push this pair inside vec
    // vec.emplace_back(5,'e'); // push this pair inside vec-> in-place objects create , this is faster than push_back;
    // for(pair <int ,char> p : vec){
    //     cout << p.first << "-" << p.second << endl;
    // }

    // ----------------------Stack------------------------------
    // This is last-in-first-out structure
    // stack <int> s ;
    // s.push(3);
    // s.push(4);
    // s.push(5);
    // s.emplace(6);

    // cout << s.top() << endl;  // return top of the element
    // s.pop() ;   // remove top element from the stack
    // cout << s.top() << endl;
    // while(!s.empty()){
    //     cout << s.top() << " " ;
    //     s.pop();
    // }
    // cout << endl;
    // cout << s.size()<<endl;

    // stack <int> s1 ;
    // s1.push(4);
    // s1.push(5);
    // s1.emplace(6);

    // stack<int>s2;
    // s2.swap(s1) ;   // It swap all the elements in the s2, and s1 will be empty

    // cout << s1.size() << endl;
    // cout << s2.size() << endl;

    // ----------------------Queue-----------------------------
    // It is based on FIFO(First-in-first-out) structure
    // queue<int> q;

    // q.push(1);
    // q.push(2);
    // q.push(3);

    // while(!q.empty()){
    //     cout << q.front() << endl;
    //     q.pop();
    // }
    // cout << "size of q is : "<< q.size() <<endl;

    // queue<int> q;

    // q.push(1);
    // q.push(2);
    // q.push(3);
    // queue<int> q2;
    // q2.swap(q);  // same as stack
    // cout << q.size() << endl;
    // cout << q2.size() << endl;

    // -----------------priority queue------------------------
    // It internally use maxHeap or minHeap structure , as it;s complete binary tree so priority queue internally uses tree structure
    // In priority queue time complexity of top - O(1), push ,emplace and pop - O(logn)
    // It sort the element the sorted format
    
    // -- It default behaviour is highest to lowest
    // priority_queue <int> pq;
    // pq.push(3);
    // pq.push(4);
    // pq.push(5);
    // pq.emplace(10);
    // pq.emplace(1);

    // -- If we want It default behaviour is lowest to highest then
    // priority_queue <int, vector<int>,greater<int>> pq;   // here greater is functor means function object , we can consider it;s comparator

    // pq.push(3);
    // pq.push(4);
    // pq.push(5);
    // pq.emplace(10);
    // pq.emplace(1);

    // cout << pq.size() << endl;
    // cout << pq.top() << endl;   // returns 10 , because maximum value are in the top
    // while(!pq.empty()){
    //     cout << pq.top() << " ";
    //     pq.pop();
    // }

    // -------------------------------Map----------------------------
    // It is used to store key,value pairs, It automatically ascending order sort based on key, It is implemented as self balance tree
    // Time Complexity : erase,insert,count - O(logn)
    // map<string,int> m;

    // m["tv"] = 1000;
    // m["laptop"] = 45000;
    // m["phone"] = 10000;

    // m.insert({"headphones",1000});
    // m.emplace("camera",5000);
   
    // for(auto p : m){
    //     cout << p.first << "-" << p.second << endl;
    // }

    // cout << m.count("laptop") << endl;  // returns count of keys, laptop has single key, so return 1
    // m.erase("camera");
    // cout << m.count("camera") << endl;
     
    // if(m.find("headphones") != m.end()){ // If found then return iterator else got m.end()
    //     cout << "found" << endl;
    // }else{
    //     cout << "not found" << endl;
    // }
    // cout << m.empty() << endl;

    // ---------Other maps :
    // 1 : Multi Map :- we can not use square notation, we will use insert or emplace function. It has exists duplicate keys

    // multimap<string,int> mp;
    // mp.emplace("tv",1000);
    // mp.emplace("tv",1000);
    // mp.emplace("tv",1000);
    // mp.emplace("tv",1000);

    // for(auto p : mp){
    //     cout << p.first << "-" << p.second << endl;  // It returns 4 time tv , but instead of multimap, map is there then map returs one time tv
    // }
    // // mp.erase("tv"); // can also pass iterator
    // mp.erase(mp.find("tv"));
    // cout << endl;
    // for(auto p : mp){
    //     cout << p.first << "-" << p.second << endl;  // not returns anything because erase function clear the key of tv
    // }

    // 2 : Unordered Map
    // Time Complexity : erase,insert,count - O(1)
    // unordered_map <string,int> um;
    // um.insert({"tv",1000});
    // um.insert({"camera",1000});
    // um.emplace("camera",2000);

    // for(auto p : um){
    //     cout << p.first << "-" << p.second << endl;  // not returns anything because erase function clear the key of tv
    // }

    // --------------------------Set-------------------------
    // It stores unique values and sorted, ignore duplicates. Internally set is similar to map.
    // Time Complexity : erase,insert,count - O(logn)
    // set <int > s;
    // s.insert(1);
    // s.emplace(2);
    // s.insert(2);
    // // s.insert(3);
    // s.insert(4);
    // s.emplace(0);

    // for(auto val:s){
    //     cout << val << endl;
    // }

    // cout <<"Size is : " << s.size() << endl;
    // cout <<"Lower bound is :"<< *(s.lower_bound(3)) <<endl; // It means min value is 3 , if not then get value of just bigger than 4 and if 4 is not also not exists then it return s.end() means last indexed value .
    // cout <<"Upper bound is :"<< *(s.upper_bound(1)) <<endl;

    // lower_bound() - should not be less than key
    // upper_bound() - should be greater than key

    // --------Other Sets
    // 1-Multi sets :- it can also store duplicate values. return in ascending order -sorted - O(logn) time complexity
    // multiset <int > s;
    // s.insert(1);
    // s.emplace(2);
    // s.insert(2);
    // s.insert(4);

    // for(auto val:s){
    //     cout << val << endl;
    // }


    // 2-Unordered sets
    // cannnot store duplicate values . Return in any order - not sorted - O(1) time complexity
    // not exists lower_bound and upper_bound because it's possible when data is sorted
    // unordered_set <int > s;
    // s.insert(1);
    // s.emplace(2);
    // s.insert(4);
    // s.insert(2);

    // for(auto val:s){
    //     cout << val << endl;
    // }


    // ---------------------Algorithms-------------------------------
    // ------Sorting
    // 1- sort(arr,arr+n)
    // 2- sort(arr,arr+n,greater<int>())
    // 3- sort(v.begin(),v.end())

    // int arr[8] = {2,3,5,7,9,7,3,1};
    // sort(arr,arr+8);  // sort in ascending order
    // sort(arr,arr+8,greater<int>());    // greater<int>() is a functor, sort in descending order

    // vector <int> vec = {2,2,5,7,9,4,3,1};
    // sort(vec.begin(),vec.end());  // sort in ascending order
    // sort(vec.begin(),vec.end(),greater<int>());  // sort in descending order
    // If we want to in descending order then
    

    // for(auto val : arr){
    //     cout << val << " ";
    // }
    // cout << endl;
    // for(auto val : vec){
    //     cout << val << " ";
    // }

    // vector<pair <int,int>> ob = {{2,3},{4,5},{6,1}};
    // sort(ob.begin(),ob.end());  // sort in according to 1st value
    // If we want to sort in 2nd value then we can use our custom functor

    // sort(ob.begin(),ob.end(),comparator);   // sorted according to 2nd value

    // vector<pair <int,int>> ob = {{2,3},{1,3},{6,1},{5,1}};
    // sort(ob.begin(),ob.end(),comparator2);  // sort on the basis of 1st value if 2nd value is same
    // for(auto val : ob){
    //     cout << val.first << "-" << val.second << endl;
    // }

    // -----Reverse
    // vector <int> vec = {2,2,5,7,9,4,3,1};
    // // reverse(vec.begin(),vec.end());
    //  reverse(vec.begin()+1,vec.end()-2);
    // for(auto val : vec){
    //     cout << val  << " ";
    // }

    // ------next_permutation
    // string s  = "abc";
    // next_permutation(s.begin(),s.end());
    // cout << s;
    
    //----max and min elements
    // vector <int> vec = {2,2,5,7,9,4,3,1};
    // cout << *(max_element(vec.begin(),vec.end())) << endl;  // return max element in the array
    // cout << *(min_element(vec.begin(),vec.end())) << endl;  // return min element in the array

    // ---binary search
    // vector <int> vec = {2,2,5,7,9,4,3,1};
    // cout << binary_search(vec.begin(),vec.end(),7);   // it return true or false means 1 or 0 that this element is exists in the array or not

    // ----Count set bits
    These function is based on gcc c++ compiler
    // __builtin_popcount()
    // __builtin_popcountl()
    // __builtin_popcountll()

    int n = 15;
    count << __builtin_popcount(n) << endl;

    return 0;

}
