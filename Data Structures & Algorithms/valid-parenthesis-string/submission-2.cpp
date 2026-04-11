class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        stack<int> open, star;

        for(int i=0;i<n;i++) {
            if(s[i] == '(')
                open.push(i);
            else if(s[i] == '*')
                star.push(i);
            else {
                if(open.empty()) {
                    if(star.empty())
                        return false;
                    
                    star.pop();
                    continue;
                }
                open.pop();
            }
        }
        
        while(!open.empty() && !star.empty()) {
            int i = open.top();
            int j = star.top();

            if(j < i)   return false;

            open.pop();
            star.pop();
        }

        return open.size() <= star.size();
    }
};
