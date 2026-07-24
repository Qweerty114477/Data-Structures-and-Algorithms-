#include<bits/stdc++.h>
using namespace std;
   class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node (int data1){
        this->data=data1;
        this->left=NULL;
        this->right=NULL;
    }
   };
   Node* builttree(Node* root){
    cout<<"Enter Data"<<endl;
    int num;
    cin>>num;
    Node* temp=new Node(num);
    if(num==-1){
        return NULL;
    }
    cout<<"Enter The number to left of "<<num<<endl;
    temp->left=builttree(temp->left);
    cout<<"Enter the number to right of "<<num<<endl;
    temp->right=builttree(temp->right);
    return temp;
   }
   void levelorderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
   }
   int main(){
    Node* root=NULL;
    root =builttree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    levelorderTraversal(root);
    return 0;
   }