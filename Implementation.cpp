#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data1){
        this->data=data1;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* builtTree(Node* root){
    cout<<"Enter The data"<<endl;
    int data;
    cin>>data;
    Node * newnode=new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter the data to left of "<<data<<endl;
   // cin>>data;
    newnode->left=builtTree(newnode->left);
    cout<<"Enter the data to right of "<<data<<endl;
   // cin>>data;
   newnode->right=builtTree(newnode->right);
   return newnode;
}
int main(){
    Node* root=NULL;
    root=builtTree(root);
    return 0;
}