class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        int i = 0, j = 0;
        string combo = "";
        while(i < n && j < m) {
            combo += word1[i++];
            combo += word2[j++];
        }

        while(i < n) {
            combo += word1[i++];
        }

        while(j < m) {
            combo += word2[j++];
        }

        return combo;
    }
};