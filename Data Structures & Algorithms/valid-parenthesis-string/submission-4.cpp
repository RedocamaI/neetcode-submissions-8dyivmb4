class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        stack<int> left, star;

        for(int i=0;i<n;i++) {
            if(s[i] == '(')
                left.push(i);
            else if(s[i] == '*')
                star.push(i);
            else {
                if(left.empty()) {
                    if(star.empty())
                        return false;
                    
                    star.pop();
                    continue;
                }
                left.pop();
            }
        }

        while(!left.empty() && !star.empty()) {
            int i = left.top();
            int j = star.top();

            if(i > j)   return false;

            left.pop();
            star.pop();
        }

        return left.empty();
    }
};
