class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for(auto& flight:flights) {
            int src = flight[0];
            int dest = flight[1];
            int price = flight[2];

            adj[src].push_back({dest, price});
        }

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        queue<vector<int>> q;
        q.push({0, src, 0});
        while(!q.empty()) {
            int stops = q.front()[0];
            int dest = q.front()[1];
            int price = q.front()[2];

            q.pop();
            if(dest == dst)
                continue;
            if(stops > k)
                    continue;
            for(auto& node:adj[dest]) {
                int nodeVal = node.first;
                int cost = node.second;
                if(dist[nodeVal] > price + cost) {
                    dist[nodeVal] = price + cost;
                    q.push({stops + 1, nodeVal, dist[nodeVal]});
                }
            }
        }

        if(dist[dst] == 1e9)
            return -1;
        
        return dist[dst];
    }
};
