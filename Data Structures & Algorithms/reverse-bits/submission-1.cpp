class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int y = 31;
        while(y >= 16) {
            int x = 31-y;
            bool ySet = n & (1<<y);
            bool xSet = n & (1<<x);

            if(ySet ^ xSet) {
                n ^= (1 << x);
                n ^= (1 << y);
            }

            y--;
        }

        return n;
    }
};
