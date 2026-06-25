#include<bits/stdc++.h>
using namespace std;
  class Node {
    public:
    int data;
    Node* next;
    public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    Node (int data1){
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
  void print( Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
  }
  Node* insertAtk(Node* head,int k,int val){
    if(head==NULL) {
        if(k==1) return new Node(val);
        else return NULL;
    }
    if(k==1){
        Node* temp=new Node(val,head);
        return temp;
    }
    Node* temp=head;
    int cnt=0;
    while(temp){
        cnt++;
        if(cnt==k-1){
            Node* ans=new Node(val);
            ans->next=temp->next;
            temp->next=ans;
            break;
        }
        temp=temp->next;
    }
    return head;
  }
int main(){
    vector<int>arr={436,76,65,34,89,75};
    Node* head=convertLL(arr);
    print(head);
    head=insertAtk(head,4,1111);
    print(head);
    return 0;
}