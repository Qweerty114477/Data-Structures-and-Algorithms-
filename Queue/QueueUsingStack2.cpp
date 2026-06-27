#include<bits/stdc++.h>
using namespace std;
class MyQueue {
    private:
    stack<int>s1,s2;
    public:
    void push(int x){
        s1.push(x);
    }
    int pop(){
        if(s1.empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int ele=s2.top();
        s2.pop();
        if(s2.empty()){
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
        return ele;
    }
    int front(){
        if(s1.empty()){
            cout<<"The queue is empty!!!"<<endl;
            return -1;
        }
        if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
        return s2.top();
    }
    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
};
int main(){
    MyQueue q;
    q.push(10); // O(1)
    q.push(20); // O(1)
    q.push(30); // O(1)
    
    // First pop triggers the O(N) move from s1 to s2
    cout << "Popped: " << q.pop() << endl;      // Should be 10
    
    // Second pop is O(1) because 20 is already at the top of s2!
    cout << "Popped: " << q.pop() << endl;      // Should be 20
    
    // Push while s2 still has elements? No problem! It goes straight to s1.
    q.push(40); 
    
    cout << "Front element: " << q.front() << endl; // Should be 30
    return 0;
}