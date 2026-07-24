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
        right=nullptr;
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
    cout<<"Enter the data to left of :"<<endl;
    temp->left=builttree(temp->left);
    cout<<"Enter the data to right of "<<endl;
    temp->right=builttree(temp->right);
    return temp;
}
void postorder(node * root){
    if(root==NULL){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){
    node* root=NULL;
    root=builttree(root);
    postorder(root);
    return 0;
}