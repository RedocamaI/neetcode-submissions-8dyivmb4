class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        if(n == 1)  return stones[0];

        priority_queue<int> hp;
        for(int i=0;i<n;i++){
            hp.push(stones[i]);
        }

        while(hp.size() >= 2){
            int stone1 = hp.top();
            hp.pop();
            int stone2 = hp.top();
            hp.pop();

            if(stone1 > stone2)
                hp.push(stone1 - stone2);
        }

        return (hp.size() == 0 ? 0 : hp.top());
    }
};
