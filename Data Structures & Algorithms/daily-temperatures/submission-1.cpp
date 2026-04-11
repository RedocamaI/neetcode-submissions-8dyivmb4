class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> res(n, 0);

        for(int i=n-2;i>=0;i--){
            int j = i+1;
            while(j < n && temp[j] <= temp[i]){
                if(res[j] == 0){
                    j = n;
                    break;
                }
                j += res[j];
            }

            if(j < n)
                res[i] = j-i;
        }

        return res;
    }
};
