class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        vector<int> topo;
        vector<int> indegree(n, 0);

        for(auto& courseSet:pre) {
            int course = courseSet[0];
            int preReq = courseSet[1];

            indegree[course]++;
            adj[preReq].push_back(course);
        }

        queue<int> q;
        for(int i=0;i<indegree.size();i++) {
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()) {
            int course = q.front();
            q.pop();
            topo.push_back(course);

            for(auto& node:adj[course]) {
                indegree[node]--;
                if(indegree[node] == 0)
                    q.push(node);
            }
        }

        if(topo.size() == n)
            return topo;
        return {};
    }
};
