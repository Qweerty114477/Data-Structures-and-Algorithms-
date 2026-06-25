#include<bits/stdc++.h>
using namespace std;
   class Node {
    public:
    int data;
    Node* next;
    public:
    Node (int data1,Node* next1){
        data=data1;
        next=next1;
    }
    Node (int data1){
        data=data1;
        next=nullptr;
    }
   };
   Node* convertarr (vector<int>&arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
   }
   Node* insertH (Node* head,int val){
    Node* temp=new Node(val,head);
    return temp;
   }
   Node* insertTail (Node* head,int val){
    if(head==NULL){
        return new Node(val);
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* newnode=new Node(val);
    temp->next=newnode;
    return head;
   }
   void print(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
   }

   int main(){
    vector<int>arr={34,24,65,87,48,90};
    Node* head=convertarr(arr);
    print(head);
    head=insertH(head,99);
   // head= new Node(99,head);
   head=insertTail(head,100);
   
    print(head);
    return 0;
   }