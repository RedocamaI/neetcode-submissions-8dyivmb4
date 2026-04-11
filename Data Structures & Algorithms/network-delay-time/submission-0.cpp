class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> vis(n+1, 0);
        vector<int> dist(n+1, 1e9);
        unordered_map<int, vector<pair<int, int>>> adj;
        priority_queue<pair<int, int>, 
        vector<pair<int, int>>, greater<pair<int, int>>
        > pq;

        for(auto& time:times) {
            int origin = time[0];
            int dest = time[1];
            int t = time[2];

            adj[origin].push_back({dest, t});
        }

        pq.push({0, k});
        vis[k] = 1;
        dist[k] = 0;
        while(!pq.empty()) {
            int origin = pq.top().second;
            int time = min(pq.top().first, dist[origin]);

            pq.pop();
            for(auto& adjList:adj[origin]) {
                int dest = adjList.first;
                int t = adjList.second;

                if(vis[dest]) {
                    dist[dest] = min(dist[dest], time+t);
                    continue;
                }
                
                pq.push({time+t, dest});
                vis[dest] = 1;
                dist[dest] = min(dist[dest], time+t);
            }
        }

        int time = -1e9;
        for(int i=1;i<=n;i++) {
            if(dist[i] == 1e9)
                return -1;
            
            time = max(time, dist[i]);
        }

        return time;
    }
};
