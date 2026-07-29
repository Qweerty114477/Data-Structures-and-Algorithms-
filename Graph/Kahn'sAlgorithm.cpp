/*
class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {

        // Create adjacency list
        vector<vector<int>> adj(V);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        // Calculate indegree of each vertex
        vector<int> indegree(V, 0);

        for (int i = 0; i < V; i++) {
            for (auto neighbour : adj[i]) {
                indegree[neighbour]++;
            }
        }

        // Push all vertices with indegree 0 into the queue
        queue<int> q;

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        // Kahn's Algorithm (BFS)
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (auto neighbour : adj[node]) {

                indegree[neighbour]--;

                if (indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        return ans;
    }
};
*/