class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ump;
        for(auto& str:strs){
            string word = str;
            vector<int> freq(26, 0);
            for(auto& c:word){
                freq[c%97]++;
            }
            string key = "";
            for(int i=0;i<26;i++){
                key += char(freq[i]);
            }

            ump[key].push_back(str);
        }

        vector<vector<string>> ans;
        for(auto& it:ump){
            ans.push_back(it.second);
        }

        return ans;
    }
};
