#include<bits/stdc++.h>
using namespace std;
class Stack{
    private:
    int arr[10];
    int top;
    public:
    Stack(){
        top=-1;
    }
    void push(int x){
        if(top==9){
            cout<<"Stack overflow"<<endl;
            return;
        }
        top+=1;
        arr[top]=x;
        cout<<x<<"pushed into the stack"<<endl;
    }
    void pop(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        cout<<arr[top]<<"popped from stack"<<endl;
        top-=1;

    }
    int peek(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
            return-1;
        }
        return arr[top];
    }
    bool isEmpty(){
        return top==-1;
    }
    int size(){
        return top+1;
    }
};
int main(){
    Stack st;
    st.push(10);
    st.push(40);
    st.push(30);
    cout<<"Top element: "<<st.peek()<<endl;
    cout <<"Size: "<< st.size()<<endl;

    st.pop();

    cout<<"Top element after pop: "<<st.peek() << endl;
    cout<<"Size: "<<st.size()<<endl;
    return 0;
}