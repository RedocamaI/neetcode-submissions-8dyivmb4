class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        for(int i=0;i<n;i++) {
            int start = i;
            if(cost[start] > gas[start])
                continue;
            
            int tank = gas[i];
            int j = start;
            tank -= cost[i];
            j = (j+1)%n;
            while(true) {
                if(j == start)  return j;

                tank = tank + gas[j] - cost[j];
                if(tank < 0)    break;
                j = (j+1)%n;
            }
        }

        return -1;
    }
};
