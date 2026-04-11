class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size();
        int m = s1.size();
        sort(s1.begin(), s1.end());

        if(n == m){
            sort(s2.begin(), s2.end());
            return s1 == s2;
        }

        for(int i=0;i<n-m+1;i++){
            string sub = s2.substr(i, m);
            sort(sub.begin(), sub.end());

            if(s1 == sub)   return true;
        }

        return false;
    }
};
