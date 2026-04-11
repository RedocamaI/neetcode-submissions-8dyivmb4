class Solution {
public:
    int trap(vector<int>& ht) {
        int n = ht.size();

        vector<int> nl(n, -1);
        vector<int> pl(n, -1);

        for(int i=1;i<n;i++){
            pl[i] = max(pl[i-1], ht[i-1]);
        }

        for(int i=n-2;i>=0;i--){
            nl[i] = max(nl[i+1], ht[i+1]);
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            int val = (min(nl[i], pl[i]) - ht[i]);
            ans += (val < 0 ? 0 : val);
        }

        return ans;
    }
};
