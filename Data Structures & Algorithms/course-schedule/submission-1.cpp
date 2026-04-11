class Solution {
public:
    bool isCycle(int i, vector<int>adj[], vector<int>& vis, vector<int>& pathVis) {
        vis[i] = 1;
        pathVis[i] = 1;
        for(auto& node:adj[i]) {
            if(pathVis[node])
                return true;
            if(isCycle(node, adj, vis, pathVis))
                return true;
        }

        // returning from the current path:
        pathVis[i] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto& courseSet:prerequisites) {
            int course = courseSet[0];
            int prerequisite = courseSet[1];

            adj[prerequisite].push_back(course);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for(int i=0;i<numCourses;i++) {
            if(vis[i])
                continue;
            if(isCycle(i, adj, vis, pathVis))
                return false;
        }

        return true;
    }
};
