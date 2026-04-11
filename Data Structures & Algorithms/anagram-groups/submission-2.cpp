class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ump;

        for(auto& word:strs) {
            vector<int> freq(26, 0);
            string key = "";
            for(auto& ch:word) {
                freq[ch%97]++;
            }
            
            for(int i=0;i<26;i++){
                key += char(freq[i]);
            }

            ump[key].push_back(word);
        }

        vector<vector<string>> ans;
        for(auto& it:ump) {
            ans.push_back(it.second);
        }

        return ans;
    }
};
