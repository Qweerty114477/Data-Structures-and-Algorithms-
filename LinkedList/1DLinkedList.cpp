#include<bits/stdc++.h>
using namespace std;
    struct Node{
        public :
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
    int main(){
        vector<int>arr={2,5,8,7};
        Node* y=new Node(arr[0],nullptr);
        Node y1=Node(arr[0],nullptr);
        Node* y=new Node(arr[0]);
        cout<<y1.data<<endl;
        cout<<y1.next<<endl;
        cout<<y->data<<endl;
        cout<<y<<endl;
    }