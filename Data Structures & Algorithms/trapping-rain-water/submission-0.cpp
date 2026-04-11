class Solution {
public:
    int trap(vector<int>& ht) {
        int n = ht.size();

        vector<int> nl(n, -1);
        vector<int> pl(n, -1);

        // evaluate nl:
        stack<int> st;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && ht[st.top()] <= ht[i]){
                st.pop();
            }

            nl[i] = st.empty() ? -1 : st.top();
            if(st.empty())  st.push(i);
        }

        while(!st.empty())  st.pop();

        // evaluate pl:
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && ht[st.top()] <= ht[i]){
                st.pop();
            }

            pl[i] = st.empty() ? -1 : st.top();
            if(st.empty())  st.push(i);
        }

        // cout << "nl: \n";
        // for(auto& val:nl){
        //     cout << val << ", ";
        // }
        // cout << "\n";

        // cout << "pl: \n";
        // for(auto& val:pl){
        //     cout << val << ", ";
        // }
        // cout << "\n";

        // calculate the ans:
        int ans = 0;
        for(int i=0;i<n;i++){
            if(nl[i] == -1 || pl[i] == -1)  continue;
            ans += (min(ht[nl[i]], ht[pl[i]])-ht[i]);
        }

        return ans;
    }
};
