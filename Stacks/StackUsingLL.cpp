#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
class Stack{
    private:
    Node* top;
    int size1=0;
    
    public:
    Stack(){
        top=nullptr;
    }
    void push(int x){
        Node* temp=new Node(x);
        temp->next=top;
        top=temp;
        size1++;
    }
    void pop(){
        if (top==nullptr){
            cout<<"Stack Underflow! Cannot pop."<<endl;
            return;
        }
        Node* temp=top;
        top=top->next;
        delete temp;
        size1--;
    }
    int top1(){
        if (top==nullptr) {
            cout<<"Stack is empty!";
            return -1; // Returning an error sentinel value
        }
        return top->data;
    }
    int size(){
        return size1;
    }
    bool isEmpty(){
        return top==nullptr;
    }
};
int main(){
    Stack st;
    st.push(89);
    st.push(31);
    st.push(56);
    st.top1();
    st.pop();
    return 0;
}