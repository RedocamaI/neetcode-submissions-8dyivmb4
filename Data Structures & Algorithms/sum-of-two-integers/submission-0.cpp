class Solution {
public:
    int getSum(int a, int b) {
        while(b) {
            // create the carry:
            int carry = (a&b) << 1;

            // find partial sum: sum without carry
            a = a ^ b;

            // add the carry again:
            b = carry;
        }

        return a;
    }
};
