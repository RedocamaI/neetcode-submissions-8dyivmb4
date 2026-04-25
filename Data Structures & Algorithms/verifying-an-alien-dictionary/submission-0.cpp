class Solution {
public:
    bool isGreater(string& word1, string& word2,
    unordered_map<char, int>& alphabets) {
        int n = word1.size();
        int m = word2.size();
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(alphabets[word1[i]] > alphabets[word2[j]]) {
                return true;
            }else if(alphabets[word1[i]] < alphabets[word2[j]]) {
                return false;
            }

            i++;
            j++;
        }

        if(i < n && j >= m)
            return true;

        return false;
    }

    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> alphabets;

        int n = order.size();
        for(int i=0;i<n;i++) {
            alphabets[order[i]] = i;
        }

        n = words.size();
        for(int i=1;i<n;i++) {
            string word1 = words[i-1];
            string word2 = words[i];

            if(isGreater(word1, word2, alphabets))
                return false;
        }

        return true;
    }
};