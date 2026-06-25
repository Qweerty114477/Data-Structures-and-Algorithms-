#include<bits/stdc++.h>
using namespace std;
  class Node{
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
  Node* convertLL (vector<int>&arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
  }
  Node* deletehead (Node* head){
   // Node* head=new Node(arr[0]);
    if(head==NULL) return head;
    Node* temp=head;
    head=head->next;
    delete(temp);
    return head;
  }
  Node* removetail (Node* head){
    if(head==NULL||head->next==NULL) return NULL;
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
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
    vector<int>arr={10,89,34,65,84};
    Node* head=convertLL(arr);
    head=removetail(head);
    print(head);
    return 0;
   }