class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> ump;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        ump[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string, int>> vec;
        vec = ump[key];
        int l = 0;
        int h = vec.size()-1;
        int ans = -1;
        while(l <= h){
            int mid = l + (h-l)/2;

            if(vec[mid].second == timestamp)
                return vec[mid].first;
            
            if(vec[mid].second > timestamp)
                h = mid-1;
            else{
                ans = mid;
                l = mid+1;
            }
        }

        if(ans == -1 || vec[ans].second > timestamp)
            return "";
        
        return vec[ans].first;
    }
};
