class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded = "";
        for(auto& word:strs){
            encoded += (to_string(word.size()) + "l" + word);
        }

        return encoded;
    }

    pair<int, int> calcLength(int i, string s) {
        string lVal = "";
        while(s[i] != 'l'){
            lVal += s[i];
            i++;
        }

        int l = stoi(lVal);
        return {l, lVal.size()+1};
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        string word = "";
        int n = s.size();
        int i = 0;
        while(i < n) {
            pair<int,int> p = calcLength(i, s);
            i += p.second;
            int l = p.first;
            int j = i+l;
            while(i < j){
                word += s[i];
                i++;
            }

            decoded.push_back(word);
            word = "";
        }

        return decoded;
    }
};
