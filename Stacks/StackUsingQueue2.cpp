#include<bits/stdc++.h>
using namespace std;
class MyStack{
    private:
    queue<int>q;
    public:
    void push(int x){
        q.push(x);
    }
    int pop(){
        if(q.empty()){
            cout<<"Stack is empty!!"<<endl;
            return-1;
        }
        int n=q.size();
        for(int i=0;i<n-1;i++){
            q.push(q.front());
            q.pop();
        }
        int ele=q.front();
        q.pop();
        return ele;
    }
        int top(){
            if (q.empty()) {
            cout << "Stack is empty!!" << endl;
            return -1;
        }
            return q.back();
        }
        bool isEmpty(){
            return q.size()==0;
        }
    
};
int main(){
    MyStack s;
    s.push(10); // Super fast O(1)
    s.push(20); // Super fast O(1)
    s.push(30); // Super fast O(1)

    cout << "Top element: " << s.top() << endl; // Outputs 30 (Fast O(1))
    
    // This pop takes O(N) because it has to rotate the queue
    cout << "Popped: " << s.pop() << endl;      // Outputs 30 
    cout << "New Top: " << s.top() << endl;     // Outputs 20
    return 0;
}