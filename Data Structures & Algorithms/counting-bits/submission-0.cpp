class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits;
        bits.push_back(0);
        for(int i=1;i<=n;i++) {
            int bit = 0;
            int x = i;
            while(x > 0) {
                bit += (x & 1);
                x >>= 1;
            }

            bits.push_back(bit);
        }

        return bits;
    }
};
