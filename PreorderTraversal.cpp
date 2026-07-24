#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;

    }
};
node* builttree(node* root){
    cout<<"Enter the data : "<<endl;
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    node* temp=new node(data);
    cout<<"Enter the data to left of : "<<data<<endl;
    temp->left=builttree(temp->left);
    cout<<"Enter the data To right of : "<<data<<endl;
    temp->right=builttree(temp->right);
    return temp;
}
void preorder(node* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    node* root=NULL;
    root=builttree(root);
    preorder(root);
    return 0;
}