class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(m > n)   return "";

        unordered_map<char, int> freq1;
        for(int i=0;i<m;i++){
            freq1[t[i]]++;
        }
        int need = 0;
        for(auto& it:freq1)  need += (it.second > 0 ? 1 : 0);
        cout << "need: " << need << "\n";

        int l = 0;
        int i = 0, j = 1000;
        int have = 0;
        unordered_map<char, int> freq2;
        for(int r=0;r<n;r++){
            freq2[s[r]]++;
            
            if(freq1[s[r]] && freq1[s[r]] <= freq2[s[r]]){
                if(freq1[s[r]] <= freq2[s[r]]-1)    continue;
                have++;
            }
            
            while(r-l+1 >= m && have == need){
                if((j-i+1) > (r-l+1)){
                    i = l;
                    j = r;
                }

                freq2[s[l]]--;
                if(freq1[s[l]] > freq2[s[l]])   have--;
                l++;
            }
        }

        string ans = "";
        if(j == 1000)   return "";
        for(int p=i;p<=j;p++){
            ans += s[p];
        }

        return ans;
    }
};
