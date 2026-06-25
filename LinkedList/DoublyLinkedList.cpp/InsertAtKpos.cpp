#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node* back;
    public:
    Node (int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
    Node (int data){
        this->data=data;
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
Node* insertatkpos(Node* head,int k,int val){
    
    if(k==1){
       Node* temp=new Node(val,head,nullptr);
       head->back=temp;
       return temp;
    }
    int cnt=0;
    Node* temp=head;
    while(temp){
        cnt++;
        if(cnt==k){
            break;
        }
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* newnode=new Node(val,temp,prev);
    prev->next=newnode;
    temp->back=newnode;
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
void insertbeforenode(Node* node,int val){
    Node* prev=node->back;
  //  Node* front=node->next;
    Node* newnode=new Node(val,node,prev);
    prev->next=newnode;
    node->back=newnode;
}
int main(){
    vector<int>arr={23,74,253,67,463,96,89};
    Node* head=convertDLL(arr);
    print(head);
  //  head=insertatkpos(head,1,436);
  insertbeforenode(head->next,45234);
    print(head);
    return 0;
}