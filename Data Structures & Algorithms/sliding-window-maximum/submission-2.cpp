class Compare {
public:
    bool operator()(pair<int, int>& a, pair<int, int>& b){
        if(a.first == b.first)  return a.second > b.second;
        return a.first < b.first;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        int n = nums.size();
        vector<int> ans;

        int l = 0;
        for(int r=0;r<n;r++){
            pq.push({nums[r], r});

            if(r-l+1 < k)   continue;

            int maxi = pq.top().second;
            while(!pq.empty() && maxi < l){
                pq.pop();

                if(!pq.empty())
                    maxi = pq.top().second;
            }

            int maxel = pq.top().first;
            // cout << "r: " << r << ", maxel: " << maxel << "\n";
            ans.push_back(maxel);
            if(maxel == nums[l])   pq.pop();
            l++;
        }

        return ans;
    }
};