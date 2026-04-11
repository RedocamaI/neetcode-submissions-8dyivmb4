class Solution {
public:
    bool includes(int l, int r, 
    unordered_map<char, int>& freq1, 
    unordered_map<char, int>& freq2){
        int n = freq1.size();
        int m = freq2.size();

        if(m < n)   return false;
        for(auto& it:freq1){
            char c = it.first;
            int cnt = it.second;
            if(!freq2[c] || freq2[c] < cnt)  return false;
        }

        return true;
    }

    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(m > n)   return "";

        unordered_map<char, int> freq1;
        for(int i=0;i<m;i++){
            freq1[t[i]]++;
        }

        int l = 0;
        int i = 0, j = 1000;
        unordered_map<char, int> freq2;
        for(int r=0;r<n;r++){
            freq2[s[r]]++;
            while(r-l+1 >= m && includes(l, r, freq1, freq2)){
                // cout << "l: " << l << "\n";
                // cout << "r: " << r << "\n";
                if((j-i+1) > (r-l+1)){
                    i = l;
                    j = r;
                }

                freq2[s[l]]--;
                l++;
            }
        }

        // cout << "i: " << i << "\n";
        // cout << "j: " << j << "\n";
        string ans = "";
        if(j == 1000)   return "";
        for(int p=i;p<=j;p++){
            ans += s[p];
        }

        return ans;
    }
};
