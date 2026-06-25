#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;
    public:
    Node (int data1,Node* next1,Node* back){
        data=data1;
        next=next1;
        back=back;
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
void print(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    vector<int>arr={34,67,54,12,89,56};
    Node* head=convertDLL(arr);
    print(head);
    return 0;
}