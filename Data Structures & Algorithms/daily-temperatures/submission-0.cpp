class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<pair<int, int>> st;
        vector<int> res(n, 0);

        st.push({n-1, temp[n-1]});
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && st.top().second <= temp[i])
                st.pop();
            
            res[i] = st.empty() ? 0 : (st.top().first - i);
            st.push({i, temp[i]});
        }

        return res;
    }
};
