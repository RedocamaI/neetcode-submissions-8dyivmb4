class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int a = 0, b = 0;
        for(auto& g:gas)
            a += g;
        
        for(auto& c:cost)
            b += c;
        
        if(b > a)   return -1;

        int total = 0;
        int start = 0;
        for(int i=0;i<gas.size();i++) {
            total += (gas[i]-cost[i]);
            if(total < 0) {
                total = 0;
                start = i+1;
            }
        }

        return start;
    }
};
