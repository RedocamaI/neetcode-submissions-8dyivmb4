class Solution {
public:
    int getHrs(vector<int>& piles, int k){
        int hrs = 0;
        for(auto& pile:piles){
            hrs += ceil(pile/(double)k);
        }

        return hrs;
    }

    int minEatingSpeed(vector<int>& piles, int hrs) {
        int l = 1;
        int h = 0;

        for(auto& pile:piles)
            h = max(h, pile);
        
        int ans = h;
        while(l <= h){
            int mid = l + (h-l)/2;

            if(getHrs(piles, mid) > hrs)
                l = mid+1;
            else{
                ans = mid;
                h = mid-1;
            }
        }

        return ans;
    }
};
