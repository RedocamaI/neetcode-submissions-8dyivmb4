class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> ump;
        for(auto& task:tasks){
            ump[task]++;
        }

        priority_queue<int> pq;
        for(auto& it:ump) {
            pq.push({it.second});
        }

        deque<pair<int, int>> q;
        int time = 0;
        while(!pq.empty() || !q.empty()){
            time++;
            int freq = !pq.empty() ? pq.top() : 0;
            freq--;

            if(!pq.empty()) pq.pop();
            if(freq > 0)    q.push_back({freq, time+n});

            if(!q.empty() && q.front().second == time){
                pq.push(q.front().first);
                q.pop_front();
            }
        }

        return time;
    }
};
