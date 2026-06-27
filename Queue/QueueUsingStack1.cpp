#include<bits/stdc++.h>
using namespace std;
class MyQueue{
    private:
    stack<int>s1,s2;
    public:
    void push(int x){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    int pop(){
        if(s1.empty()){
            cout<<"Queue is Empty!!"<<endl;
            return -1;
        }
        int ele=s1.top();
        s1.pop();
        return ele;
    }
    int front(){
        if(s1.empty()) {
            cout << "Queue is Empty!!" << endl;
            return -1;
        }
        return s1.top();
    }
    int size1(){
        return s1.size();
    }
    bool isEmpty() {
        return s1.empty();
    }
};
int main(){
    MyQueue q;
    
    q.push(10);
    q.push(20);
    q.push(30);
    
    cout << "Front element: " << q.front() << endl; // Should be 10
    
    cout << "Popped: " << q.pop() << endl;          // Should pop 10
    cout << "New Front: " << q.front() << endl;     // Should be 20
    return 0;
}