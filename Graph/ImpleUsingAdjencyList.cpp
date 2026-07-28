#include<bits/stdc++.h>
using namespace std;
 class graph{
    public:
    unordered_map<int,vector<int>>mpp;
    void addedge(int u,int v,bool direction){
        mpp[u].push_back(v);
        if(!direction){
            mpp[v].push_back(u);
        }
    }
    void print (){
        for(auto it:mpp){
            cout<<it.first<<"-->";
            for(auto it1:it.second){
                cout<<it1<<",";
            }
            cout<<endl;
        }
    }
 };
int main(){
    graph g;
    cout<<"Enter the number of Node "<<endl;
    int n,m;
    cin>>n;
    cout<<"Enter the number of Edge"<<endl;
    cin>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addedge(u,v,false);
    }
    g.print();
    return 0;
}