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
void builtfromLevelOrder(node* &root){
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;
    if(data==-1){
        root=nullptr;
        return;
    }
     root=new node( data);
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        cout<<"Enter left node for : "<<temp->data<<endl;
        int leftnode;
        cin>>leftnode;
        if(leftnode!=-1){
            temp->left=new node(leftnode);
            q.push(temp->left);
        }
        cout<<"Enter right node for : "<<temp->data<<endl;
        int rightnode;
        cin>>rightnode;
        if(rightnode!=-1){
            temp->right=new node(rightnode);
            q.push(temp->right);
        }
    }
}
vector<vector<int>> levelorderTraversal(node* root){
    vector<vector<int>>ans;
    if(root==nullptr){
        return {};
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        vector<int>val;
        int n=q.size();
        for(int i=0;i<n;i++){
            node* temp=q.front();
            q.pop();
            val.push_back(temp->data);
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        ans.push_back(val);
    }
    return ans;
}
int main(){
    node* root=nullptr;
    builtfromLevelOrder(root);
    vector<vector<int>> ans1 = levelorderTraversal(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    for(auto &level : ans1){
        for(int x : level)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}