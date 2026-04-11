class Solution {
public:
    int largestRectangleArea(vector<int>& ht) {
        int n = ht.size();

        stack<int> st;
        vector<int> ps(n, -1);
        st.push(0);
        for(int i=1;i<n;i++){
            int h = ht[i];
            while(!st.empty() && h <= ht[st.top()])
                st.pop();
            

            if(st.empty())  ps[i] = -1;
            else    ps[i] = st.top();
            st.push(i);
        }

        while(!st.empty())  st.pop();

        vector<int> ns(n, n);
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            int h = ht[i];
            while(!st.empty() && h <= ht[st.top()])
                st.pop();
            
            if(st.empty())  ns[i] = n;
            else    ns[i] = st.top();
            st.push(i);
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            int l = ps[i];
            int r = ns[i];
            int len = (r-l-1);
            int area = ht[i]*len;

            ans = max(ans, area);
        }

        return ans;
    }
};
