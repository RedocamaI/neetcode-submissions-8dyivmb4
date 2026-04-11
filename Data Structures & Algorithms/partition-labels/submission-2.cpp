class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char, int> ump;

        for(int i=n-1;i>=0;i--) {
            if(ump.find(s[i]) != ump.end())
                continue;
            
            ump[s[i]] = i;
        }

        vector<int> ans;
        int i=0, j=ump[s[0]];
        int l = 1;
        ump.erase(s[0]);
        if(i == j) {
            ans.push_back(l);
            l = 0;
        }
        while(i < n) {
            l++;
            i++;

            if(ump.find(s[i]) != ump.end()) {
                j = max(j, ump[s[i]]);
                ump.erase(s[i]);
            }

            if(i == j) {
                ans.push_back(l);
                l = 0;
            }
        }

        return ans;
    }
};
