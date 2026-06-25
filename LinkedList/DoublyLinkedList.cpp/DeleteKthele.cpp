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
Node* deletehead(Node* head){
    if(head==NULL||head->next==nullptr){
        delete head;
        return NULL;
    }
    Node* temp=head;
    head=head->next;
    temp->next=nullptr;   
    head->back=nullptr;
    delete(temp);
    return head;
}
Node* deletetail(Node* head){
    if(head==NULL|| head->next==NULL) {
        delete head;
        return NULL;
    }
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Node* prev=temp->back;
    prev->next=nullptr;
    temp->back=nullptr;
    delete(temp);
    return head;
}
Node* deleteknode (Node* head,int k){
    if(head==NULL) return NULL;
    Node* knode=head;
    int cnt=0;
    while(knode){
        cnt++;
        if(cnt==k) break;
        knode=knode->next;
    }
    if(knode==NULL) return head;
    Node* prev=knode->back;
    Node* front=knode->next;
    if(prev==NULL&&front==NULL){
        return NULL;
    }
    else if(prev==NULL) {
        return deletehead(head);
        
    }
    else if(front==NULL){
        return deletetail(head);
        
    }
    prev->next=front;
    front->back=prev;
    knode->back=nullptr;
    knode->next=nullptr;
    delete(knode);
    return head;
}
void deletenode(Node* &head,Node* node){
    if(node == NULL) return;

    if(node == head){
        head = deletehead(head);
        return;
    }
    Node* prev=node->back;
    Node* front=node->next;
    if(front==NULL){
        prev->next=nullptr;
        node->back=nullptr;
        free(node);
        return;
    }
    prev->next=front;
    front->back=prev;
    node->next=nullptr;
    node->back=nullptr;
    free(node);
}
int main(){
    vector<int>arr={143,53,7,8,6,889,443,77};
    Node* head=convertDLL(arr);
    print(head);
   // head=deleteknode(head,10);
   deletenode(head,head);

    print(head);
    return 0;
}