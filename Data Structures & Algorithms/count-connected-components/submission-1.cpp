class Solution {
public:
    void traverse(int course, vector<int>adj[], vector<int>& vis) {
        vis[course] = 1;

        queue<pair<int, int>> bfs;
        bfs.push({course, -1});
        while(!bfs.empty()) {
            int node = bfs.front().first;
            int parent = bfs.front().second;

            bfs.pop();
            vis[node] = 1;

            for(auto& adjNode:adj[node]) {
                if(adjNode == parent)
                    continue;
                if(vis[adjNode])
                    continue;
                
                bfs.push({adjNode, node});
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto& edge:edges) {
            int a = edge[0];
            int b = edge[1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> vis(n, 0);
        int connectedComponents = 0;
        for(int i=0;i<n;i++) {
            if(vis[i])
                continue;
            connectedComponents++;
            traverse(i, adj, vis);
        }

        return connectedComponents;
    }
};
