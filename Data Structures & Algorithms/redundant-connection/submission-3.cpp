class Solution {
public:
    bool isCycle(int node, vector<int> adj[], vector<int>& vis) {
        queue<pair<int,int>> bfs;
        bfs.push({node, -1});

        while(!bfs.empty()) {
            int cur = bfs.front().first;
            int parent = bfs.front().second;
            vis[cur] = 1;
            bfs.pop();

            for(auto& adjNode:adj[cur]) {
                if(adjNode == parent)
                    continue;
                if(vis[adjNode])
                    return true;
                
                bfs.push({adjNode, cur});
            }
        }

        return false;
    }

    bool check(int n, vector<int> adj[]) {
        vector<int> vis(n, 0);

        for(int i=0;i<n;i++) {
            if(vis[i])
                continue;
            if(isCycle(i, adj, vis))
                return true;
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> adj[n];
        
        for(auto& edge:edges) {
            int a = edge[0];
            int b = edge[1];

            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);

            if(check(n, adj))
                return {a, b};
        }
        
        return {};
    }
};
