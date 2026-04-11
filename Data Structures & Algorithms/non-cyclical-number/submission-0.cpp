class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> ump;
        int num = n;
        while(num != 1) {
            int x = num;
            int val = 0;
            while(x > 0) {
                int digit = x%10;
                x /= 10;

                val += pow(digit, 2);
            }

            if(ump.find(val) != ump.end())
                return false;
            
            num = val;
            ump[num]++;
        }

        return true;
    }
};
