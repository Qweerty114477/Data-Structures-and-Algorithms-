#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        this->data=val;
        this->left=nullptr;
        this->right=nullptr;
    }
};
Node* insert(Node* root,int val){
    if(root==nullptr){
        return new Node(val);
    }
    if(root->data<val){
        root->right=insert(root->right,val);
    }
    else{
        root->left=insert(root->left,val);
    }
    return root;
}
Node* takeInput(Node* root){
    int val;
    cin>>val;
    while(val!=-1){
        root=insert(root,val);
        cin>>val;
    }
    return root;
}
vector<vector<int>> levelOrder(Node* root){
    vector<vector<int>>ans;
    queue<Node*>q;
    if(root == nullptr)
        return ans;
    q.push(root);
    
    while(!q.empty()){
        int n=q.size();
    for(int i=0;i<n;i++){
        vector<int>v;
        Node* temp=q.front();
        q.pop();
        v.push_back(temp->data);
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
        ans.push_back(v);
    }
  }
  return ans;
}
Node* minVal(Node* root){
    if(root==nullptr){
        return NULL;
    }
    if(root->left==NULL){
        return root;
    }
    return minVal(root->left);
}
int MinVal(Node* root){
    if(root==NULL){
        return -1;
    }
    while(root->left!=NULL){
        root=root->left;
    }
    return root->data;
}
int MaxVal(Node* root){
    if(root==NULL){
        return -1;
    }
    while(root->right!=NULL){
        root=root->right;
    }
    return root->data;
}
Node* deleteNode(Node* root,int val){
    if(root==nullptr){
        return NULL;
    }
    if(root->data==val){
        if(root->left==nullptr&&root->right==nullptr){
          //  Node* temp=root;
            delete root;
            return NULL;
        }
        else if(root->left!=NULL&&root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        else if(root->left==NULL&&root->right!=NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        else{
            int minm=minVal(root->right)->data;
            root->data=minm;
            root->right=deleteNode(root->right,minm);
            return root;
        }
    }
    else if(root->data>val){
        root->left=deleteNode(root->left,val);
        return root;
    }
    else{
        root->right=deleteNode(root->right,val);
        return root;
    }
}
int main(){
    Node* root=nullptr;
    cout<<"Enter the data in BST"<<endl;
    root=takeInput(root);
    vector<vector<int>>ans=levelOrder(root);
    for(auto it:ans){
        for(int it1:it){
            cout<<it1<<" ";
        }
        cout<<endl;
    }

    return 0;
}