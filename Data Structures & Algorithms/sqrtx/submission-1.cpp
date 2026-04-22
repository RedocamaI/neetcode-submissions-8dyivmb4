class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int h = x;
        int ans = 0;

        while(l <= h) {
            int mid = (h-l)/2 + l;

            long long square = (long long)(mid * mid);
            
            if((long long) mid * mid > x) {
                h = mid-1;
            }else if((long long) mid * mid < x) {
                l = mid+1;
                ans = mid;
            }else
                return mid;
        }

        return ans;
    }
};