class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size();
        int m = s1.size();
        if(m > n)   return false;

        unordered_map<string, int> ump;
        vector<int> freq(26, 0);

        // Storing the check key:
        for(auto& c:s1){
            freq[c%97]++;
        }
        string key = "";
        for(auto& val:freq){
            key += to_string(val);
        }
        ump[key]++;

        // calculating the initial key,
        // so that we can manipulate it
        // based on the sliding window frequency.
        freq.assign(26, 0);
        for(int i=0;i<m;i++){
            freq[s2[i]%97]++;
        }
        key = "";
        for(auto& f:freq){
            key += to_string(f);
        }
        if(ump[key])    return true;

        for(int i=1;i<n-m+1;i++){
            freq[s2[i-1]%97]--;
            freq[s2[i+m-1]%97]++;
            key = "";
            for(auto& f:freq){
                key += to_string(f);
            }
            if(ump[key])    return true;
        }

        return false;
    }
};
