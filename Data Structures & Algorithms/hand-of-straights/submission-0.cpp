class Solution {
public:
    unordered_map<int, int> ump;
    priority_queue<
    pair<int,int>, 
    vector<pair<int,int>>,
    greater<pair<int,int>>
    > mnhp;

    bool isNStraightHand(vector<int>& hand, int g) {
        if(hand.size() % g != 0)
            return false;
        
        for(auto& h:hand) {
            ump[h]++;
        }

        for(auto& it:ump) {
            mnhp.push({it.first, it.second});
        }

        int k = hand.size()/g;
        vector<pair<int,int>> vp;
        while(k--) {
            int tg = g;
            int lv = -1;
            while(tg--) {
                pair<int,int> vf = mnhp.top();
                if(lv != -1 && vf.first-1 != lv)
                    return false;
                
                lv = vf.first;
                mnhp.pop();
                if(vf.second > 1)
                    vp.push_back({vf.first, vf.second-1});
            }
            
            while(!vp.empty()) {
                mnhp.push(vp.back());
                vp.pop_back();
            }
        }

        return true;
    }
};
