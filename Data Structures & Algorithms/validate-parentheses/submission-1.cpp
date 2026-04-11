class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        unordered_map<char, char> c2o {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for(int i=0;i<n;i++){
            if(c2o.count(s[i])){
                if(!st.empty() && st.top() == c2o[s[i]])
                    st.pop();
                else    return false;
            }else   st.push(s[i]);
        }

        return st.empty();
    }
};
