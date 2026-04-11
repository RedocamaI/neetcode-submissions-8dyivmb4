class Solution {
public:
    bool isCycle(int course, vector<int>& vis,
    vector<int>adj[]) {
        vis[course] = 1;

        queue<pair<int, int>> bfs;
        bfs.push({course, -1});
        while(!bfs.empty()) {
            int course = bfs.front().first;
            int pre = bfs.front().second;

            bfs.pop();
            vis[course] = 1;

            for(auto& node:adj[course]) {
                if(node == pre)
                    continue;
                if(vis[node])
                    return true;
                bfs.push({node, course});
            }
        }

        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        
        for(auto& edge:edges) {
            int a = edge[0];
            int b = edge[1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> vis(n, 0);

        bool cycle = isCycle(0, vis, adj);
        if(cycle)
            return false;
        
        for(int i=0;i<n;i++) {
            if(vis[i] == 0)
                return false;
        }

        return true;
    }
};
