#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;
    public:
    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
    Node (int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};
Node* convertDLL(vector<int>&arr){
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
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
Node* insertbeforehead (Node* head,int val){
    Node* temp=new Node(val,head,nullptr);
    head->back=temp;
    return temp;
}
Node* insertbeforetail (Node* head,int val){
    
    Node* temp=head;
    if(temp->next==NULL){
        return insertbeforehead(temp,val);
    }
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* newnode=new Node(val,temp,prev);
    prev->next=newnode;
    newnode->next=temp;
    return head;
}
int main(){
    vector<int>arr={24,4654,68,245,79,89};
    Node* head=convertDLL(arr);
    print(head);
    head=insertbeforehead(head,23);
    print(head);
    head=insertbeforetail(head,45);
    print(head);
    return 0;
}