class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> alpha(26, 0);
        for(auto& c:s){
            alpha[c%97]++;
        }

        for(auto& c:t){
            alpha[c%97]--;
        }

        for(int i=0;i<26;i++){
            if(alpha[i] != 0)    return false;
        }

        return true;
    }
};
