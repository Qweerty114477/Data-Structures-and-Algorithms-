#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    unordered_map<int,vector<pair<int,int>>>adj;
    void addEdge(int u,int v,int weight){
        adj[u].push_back({v,weight});
    }
    void print(){
        for(auto it:adj){
            cout<<it.first<<"-->>";
            for(auto it1:it.second){
                cout<<"("<<it1.first<<","<<it1.second<<")";
            }
            cout<<endl;
        }
    }
    void dfs(int node,unordered_map<int,bool>&visited,stack<int>&st){
        visited[node]=true;
        for(auto it :adj[node]){
            if(!visited[it.first]){
                dfs(it.first,visited,st);
            }
        }
        st.push(node);
    }
    void shortestPath (int src,vector<int>&ans,stack<int>&st){
        ans[src]=0;
        while(!st.empty()){
            int temp=st.top();
            st.pop();
            if(ans[temp]!=INT_MAX){
                for(auto it:adj[temp]){
                    if(ans[temp]+it.second<ans[it.first]){
                        ans[it.first]=ans[temp]+it.second;
                    }
                }
            }
        }
    }
};
int main(){
    Graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    g.print();
    unordered_map<int,bool>visited;
    stack<int>st;
    for(int i=0;i<6;i++){
        if(!visited[i]){
            g.dfs(i,visited,st);
        }
    }
    vector<int>ans(6);
    int src=1;

    int maxm=INT_MAX;
    for(int i=0;i<6;i++){
        ans[i]=maxm;
    }
    g.shortestPath(src,ans,st);
    for(auto it :ans){
        cout<<it<<" ";
    }
    return 0;
}