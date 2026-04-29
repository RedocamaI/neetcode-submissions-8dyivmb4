class Solution {
public:
    string convertToTitle(int columnNumber) {
        unordered_map<int, char> ump;
        char ch = 'A';
        for(int i=0;i<26;i++) {
            ump[i] = ch;
            ch++;
        }

        string title = "";
        int num = columnNumber;
        while(num >= 27) {
            long long mod = (num - 1)%26;
            title += ump[mod];

            num = (num - 1)/26;
        }
        title += ump[num-1];

        reverse(title.begin(), title.end());
        return title;
    }
};