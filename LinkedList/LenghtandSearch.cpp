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
            temp=temp->next;
        }
        return head;
    }
    int len (Node* head){
        int cnt=0;
        Node* temp=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    bool checkele (Node* head,int val){
        Node* temp=head;
        while(temp){
            if(temp->data==val) return true;
            temp=temp->next;
        }
        return false;
    }
    int main(){
        vector<int>arr={89,89,46,78,56};
        Node* head=convertLL(arr);
        int ans=len(head);
        cout<<ans<<endl;
        cout<<checkele(head,89);
        return 0;
    }