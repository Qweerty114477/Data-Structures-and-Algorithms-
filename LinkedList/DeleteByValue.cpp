#include<bits/stdc++.h>
using namespace std;
   class Node {
    public:
    int data;
    Node* next;
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }
   };
   Node* convertLL(vector<int>&arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
   }
   Node* deletebyVal (Node* head, int val){
    if(head==NULL) return NULL;
    if(head->data==val){
        Node* temp=head;
        head=head->next;
        delete(temp);
        return head;
    }
    Node* temp=head;
    Node* prev=NULL;
    while(temp){
        if(temp->data==val){
            prev->next=temp->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
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
    vector<int>arr={23,54,23,4,67,45,89};
    Node* head=convertLL(arr);
    print(head);
    head=deletebyVal(head,67);
    print(head);
    return 0;
   }