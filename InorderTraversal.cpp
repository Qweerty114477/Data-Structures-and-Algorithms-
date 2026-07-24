#include<bits/stdc++.h>
using namespace std;
class node {
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
    cout<<"enter data : "<<endl;
    int num;
    cin>>num;
    if(num==-1){
        return NULL;
    }
    node* temp=new node(num);
    cout<<"Enter data to left of :"<<num<<endl;
    temp->left=builttree(temp->left);
    cout<<"Enter data to right of :"<<num<<endl;
    temp->right=builttree(temp->right);
    return temp;
}
void inorder (node* root){
    if(root ==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}
int main(){
    node* root=nullptr;
    root=builttree(root);
    inorder(root);
    return 0;
}