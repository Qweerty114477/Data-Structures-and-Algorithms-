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
    Node(int data1){
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
    }
    return head;
}
Node* deletehead(Node* head){
    if(head==NULL||head->next==NULL) return NULL;
    Node* temp=head;
    head=head->next;
    temp->next=nullptr;
    head->back=nullptr;
    free(temp);
    return head;
}
Node* deletetail(Node* head){
    if(head==NULL||head->next==NULL) return NULL;
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Node* backNode=temp->back;
    backNode->next=nullptr;
    temp->back=nullptr;
    free(temp);
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
    vector<int>arr={23,54,86,25,79,89};
    Node* head=convertDLL(arr);
    print(head);
     head=deletehead(head);
    print(head);
    head=deletetail(head);
    print(head);
    return 0;
}
