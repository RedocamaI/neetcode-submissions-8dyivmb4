class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        bool pos = false;
        int withMe = 0;
        int n = bills.size();
        int is5 = 0, is10 = 0;

        for(int i=0;i<n;i++) {
            if(bills[i] == 5) {
                withMe += bills[i];
                is5++;
            }else if(bills[i] == 10) {
                if(!is5)    return false;
                is10++;
                is5--;
            }else if(bills[i] == 20) {
                if(!is5)   return false;
                if(!is10) {
                    if(is5 < 3) return false;
                    is5 -= 3;
                    continue;
                }

                is5--;
                is10--;
            }
        }

        return true;
    }
};