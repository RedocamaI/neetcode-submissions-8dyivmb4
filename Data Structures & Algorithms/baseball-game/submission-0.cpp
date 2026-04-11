class Solution {
public:
    int calPoints(vector<string>& ops) {
        int ans = 0;
        stack<string> st;
        int n = ops.size();

        for(int i=0;i<n;i++) {
            string record = ops[i];
            if(ops[i] == "+") {
                int a = stoi(st.top());
                st.pop();

                int b = stoi(st.top());
                st.push(to_string(a));

                int c = a + b;
                record = to_string(c);
            }else if(ops[i] == "D") {
                int a = stoi(st.top());
                record = to_string(2*a);
            }else if(ops[i] == "C") {
                st.pop();
                continue;
            }

            st.push(record);
        }

        while(!st.empty()) {
            int val = stoi(st.top());
            ans += val;
            st.pop();
        }

        return ans;
    }
};