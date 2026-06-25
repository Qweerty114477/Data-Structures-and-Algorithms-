#include<bits/stdc++.h>
using namespace std;
   class Node{
    public:
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
   Node* convertLL(vector<int>&arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
       // temp=temp->next;
        mover=temp;
    }
    return head;
   }
   Node* deleteKpos (Node* head,int k){
    if(head==NULL) return NULL;
    
    if(k==1){
        Node* temp=head;
        head=temp->next;
        free(temp);
        return head;
    }
    int cnt=0;
    Node* prev=NULL;
    Node* temp=head;
    while(temp){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
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
    vector<int>arr={56,87,88,89,23};
    Node* head=convertLL(arr);
    print(head);

    head=deleteKpos(head,7);
    print(head);
    return 0;
   }