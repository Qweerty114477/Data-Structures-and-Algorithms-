#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    vector<int> dijkstra (int v,unordered_map<int,vector<pair<int,int>>>&adj,int src){
        int maxm=INT_MAX;
        vector<int>dist(v,maxm);
        set<pair<int,int>>s;
        dist[src]=0;
        s.insert({dist[src],src});
        while(!s.empty()){
            auto top=*(s.begin());
            int NodeDist=top.first;
            int Node=top.second;
            s.erase(s.begin());
            for(auto neighbour:adj[Node]){
                if(NodeDist+neighbour.second<dist[neighbour.first]){
                    auto record=s.find({dist[neighbour.first],neighbour.first});
                    if(record!=s.end()){
                        s.erase({dist[neighbour.first],neighbour.first});
                    }
                    dist[neighbour.first]=NodeDist+neighbour.second;
                    s.insert({dist[neighbour.first],neighbour.first});
                }
            }
        }
        return dist;
    }
};
int main(){
    int v=5;
    unordered_map<int,vector<pair<int,int>>>adj;
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});

    adj[1].push_back({0, 2});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});

    adj[2].push_back({0, 4});
    adj[2].push_back({1, 1});
    adj[2].push_back({4, 3});

    adj[3].push_back({1, 7});
    adj[3].push_back({4, 1});

    adj[4].push_back({2, 3});
    adj[4].push_back({3, 1});
    Solution obj;
    vector<int>ans=obj.dijkstra(v,adj,0);
    cout << "Shortest distances from source 0:\n";
    for (int i = 0; i < v; i++)
        cout << "0 -> " << i << " = " << ans[i] << '\n';
    return 0;
}