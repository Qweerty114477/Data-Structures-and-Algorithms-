#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    unordered_map<int,vector<int>>adj;
    void addedge (int u,int v,int dir){
        adj[u].push_back(v);
        if(!dir) adj[v].push_back(u);
    }
    void print(){
        for(auto it: adj){
            cout<<it.first<<"-->";
            for(auto it1:it.second){
                cout<<it1<<" ";
            }
            cout<<endl;
        }
    }
    void dfshelper (int node ,unordered_map<int,bool>&visited){
        visited[node]=true;
        cout <<node<<" ";
        for(auto it:adj[node]){
            if(!visited[it]){
                dfshelper(it,visited);
            }
        }
       // cout<<endl;
    } 
    void dfs(int start){
        unordered_map<int,bool>visited;
        cout<<"DFS Traversal starts : ";
        dfshelper(start,visited);
    }
};
int main(){
    Graph g;

    int n, m;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    cout << "Enter edges:\n";

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g.addedge(u, v, 0);   // 0 = Undirected Graph
    }

    cout << "\nAdjacency List:\n";
    g.print();

    int start;
    cout << "\nEnter starting node for DFS: ";
    cin >> start;

    g.dfs(start);
    return 0;
}