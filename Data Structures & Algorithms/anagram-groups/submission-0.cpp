class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ump;
        for(auto& str:strs){
            string word = str;
            sort(word.begin(), word.end());
            ump[word].push_back(str);
        }

        vector<vector<string>> ans;
        for(auto& it:ump){
            ans.push_back(it.second);
        }

        return ans;
    }
};
