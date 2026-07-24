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
    
    cout<<"Enter data"<<endl;
    int num;
    cin>>num;
    if(num==-1) return NULL;
    node* newnode=new node(num);
    
    cout<<"Enter the data to left of "<<num<<endl;
    newnode->left=builttree(newnode->left);
    cout<<"Enter the data to right of "<<num<<endl;
    newnode->right=builttree(newnode->right);
    return newnode;
  }
  vector<vector<int>> levelorder (node* root){
    vector<vector<int>>ans;
    if(root==NULL) return ans;
    
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        vector<int>val;
        int n=q.size();
        
        for(int i=0;i<n;i++){
            node* copy=q.front();
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
    node* root=NULL;
    root=builttree(root);
    vector<vector<int>> ans = levelorder(root);
    for(auto &level : ans){
        for(int x : level)
            cout << x << " ";
        cout << endl;
    }
    return 0;
  }