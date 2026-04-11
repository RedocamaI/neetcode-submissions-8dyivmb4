class Solution {
public:
    pair<int, int> getOperands(stack<int>& st){
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        return {a, b};
    }

    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;
        pair<int, int> operands;

        for(int i=0;i<n;i++){
            string token = tokens[i];
            if(token == "+"){
                operands = getOperands(st);
                st.push(operands.second + operands.first);
            }else if(token == "-"){
                operands = getOperands(st);
                st.push(operands.second - operands.first);
            }else if(token == "*"){
                operands = getOperands(st);
                st.push(operands.second * operands.first);
            }else if(token == "/"){
                operands = getOperands(st);
                st.push(operands.second / operands.first);
            }else{
                int val = stoi(token);
                st.push(val);
            }
        }

        return st.top();
    }
};
