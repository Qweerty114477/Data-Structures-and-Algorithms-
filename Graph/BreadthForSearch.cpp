#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    unordered_map<int,vector<int>>adj;
    void addedge (int u,int v,int direction){
        adj[u].push_back(v);
        if(!direction){
            adj[v].push_back(u);
        }
    }
    void print(){
        for(auto it:adj){
            cout<<it.first<<"-->";
            for(auto it1:it.second){
                cout<<it1<<",";
            }
            cout<<endl;
        }
    }
    void bfs(int start){
        unordered_map<int,bool>visited;
        queue<int>q;
        q.push(start);
        visited[start]=true;
        cout << "BFS Traversal: ";
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            cout<<temp<<" ";
            for(auto it:adj[temp]){
                if(!visited[it]){
                    visited[it]=true;
                    q.push(it);
                }
            }
        }
        cout<<endl;
    }
};
int main(){
    Graph g;
    cout<<"Enter the number of node : "<<endl;
    int n;
    cin>>n;
    cout<<"Enter the number of edges : "<<endl;
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addedge(u,v,0);
    }
    cout << "\nAdjacency List:\n";
    g.print();

    int start;
    cout << "\nEnter starting node for BFS: ";
    cin >> start;

    g.bfs(start);

    return 0;
}