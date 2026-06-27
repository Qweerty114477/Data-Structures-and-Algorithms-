#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    Node (int data1){
        data=data1;
        next=nullptr;
    }
};
class Queue{
    private:
    Node* start;
    Node* end;
    int size=0;
    public:
    Queue(){
        start=nullptr;
        end=nullptr;
    }
    void push(int x){
        Node* temp=new Node(x);
        if(start==NULL){
            start=end=temp;
        }
        else{
            end->next=temp;
            end=temp;
        }
        size++;
    }
    void pop(){
        if(start==NULL) {
            cout<<"Underflow"<<endl;
            return;
        }
        Node* temp=start;
        start=start->next;
        delete temp;
        size--;
        if (start == nullptr) {
            end = nullptr;
        }
    }
    int top(){
        if(start==NULL){
            cout<<"Stack is empty!!!"<<endl;
            return -1;
        }
        return start->data;
    }
    int size1(){
        return size;
    }
    bool isEmpty(){
        return start==NULL;
    }
};
int main(){
    Queue q;
    q.push(90);
    q.pop();
    q.push(78);
    return 0;
}