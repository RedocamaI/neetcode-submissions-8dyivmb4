class Solution {
public:
    int trap(vector<int>& ht) {
        int n = ht.size();

        vector<int> nl(n, -1);
        vector<int> pl(n, -1);

        for(int i=1;i<n;i++){
            int val = max(pl[i-1], ht[i-1]);
            if(ht[i] >= val) pl[i] = -1;
            else    pl[i] = val;
        }

        for(int i=n-2;i>=0;i--){
            int val = max(nl[i+1], ht[i+1]);
            if(ht[i] >= val) nl[i] = -1;
            else    nl[i] = val;
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            if(nl[i] == -1 || pl[i] == -1)  continue;
            ans += (min(nl[i], pl[i]) - ht[i]);
        }

        return ans;
    }
};
