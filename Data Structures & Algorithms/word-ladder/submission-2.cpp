class Solution {
public:
    bool found = false;

    bool isValid(string& targetWord, string& baseWord) {
        if(targetWord.size() != baseWord.size())
            return false;
        
        int diff = 0;
        for(int i=0;i<baseWord.size();i++) {
            if(targetWord[i] != baseWord[i])
                diff++;
        }

        return diff == 1;
    }

    int explore(string& beginWord, string& endWord, 
    vector<string>& wordList, vector<int>& vis) {
        if(beginWord == endWord) {
            found = true;
            return 1;
        }

        int n = wordList.size();
        int ladder = 1e9;
        for(int i=0;i<n;i++) {
            if(vis[i])
                continue;
            if(!isValid(wordList[i], beginWord))
                continue;
            
            vis[i] = 1;
            int l = explore(wordList[i], endWord, wordList, vis);
            vis[i] = 0;
        
            if(found) {
                ladder = min(ladder, l+1);
            }
        }

        return ladder;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();

        vector<int> vis(n, 0);
        int ladder = 1e9;
        for(int i=0;i<n;i++) {
            if(!isValid(wordList[i], beginWord))
                continue;
            
            found = false;
            vis[i] = 1;
            int l = explore(wordList[i], endWord, wordList, vis);
            vis[i] = 0;

            if(found) {
                ladder = min(ladder, l+1);
            }
        }

        return (ladder == 1e9 ? 0 : ladder);
    }
};
