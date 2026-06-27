#include<bits/stdc++.h>
using namespace std;
class MyStack{
    private:
    queue<int>q;
    public:
    void push(int x){
        int n=q.size();
        q.push(x);
        for(int i=0;i<n;i++){
            q.push(q.front());
            q.pop();
        }
    }
    void pop(){
        if(q.empty()){
            cout<<"Stack is empty!!"<<endl;
            return;
        }
        q.pop();
    }
    int top(){
        if(q.empty()){
            cout<<"Stack is empty!!"<<endl;
            return -1;
        }
        return q.front();
    }
    bool isEmpty(){
        return q.empty();
    }
};
int main(){
    MyStack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl; // Outputs 30
    
    s.pop();
    cout << "New Top: " << s.top() << endl;     // Outputs 20
    return 0;
}