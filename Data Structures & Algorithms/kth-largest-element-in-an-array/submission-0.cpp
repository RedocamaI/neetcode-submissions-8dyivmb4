class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for(auto& num:nums){
            if(q.size() == k){
                if(q.top() < num)   q.pop();
                else    continue;
            }
            q.push(num);
        }

        return q.top();
    }
};
