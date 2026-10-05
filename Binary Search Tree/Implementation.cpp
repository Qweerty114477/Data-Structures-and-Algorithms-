#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }
};
Node* insert (Node* &root,int val){
    if(root ==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left=insert(root->left,val);
    }
    else {
        root->right=insert(root->right,val);
    }
    return root;
}
void inorder (Node* root){
    if(root ==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}
void preorder(Node* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node * root){
    if(root==NULL){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
Node* takeinput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root =insert(root,data);
        cin>>data;
    }
    return root;
}
vector<vector<int>> levelorder (Node* root){
    vector<vector<int>>ans;
    if(root==NULL) return ans;
    
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        vector<int>val;
        int n=q.size();
        
        for(int i=0;i<n;i++){
            Node* copy=q.front();
            q.pop();
            val.push_back(copy->data);
            if(copy->left){
                q.push(copy->left);
            }
            if(copy->right){
                q.push(copy->right);
            }
        }
        ans.push_back(val);
    }
    return ans;
}
int main(){
    Node* root=nullptr;
    cout<<"Enter the data in BST"<<endl;
    root =takeinput(root);
    vector<vector<int>> ans=levelorder(root);
    for(auto it:ans){
        for(int it1:it){
            cout<<it1<<" ";
        }
        cout<<endl;
    }
    return 0;
}