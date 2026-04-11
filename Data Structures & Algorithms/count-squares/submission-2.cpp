class CountSquares {
public:
    vector<vector<int>> points;
    unordered_map<int, unordered_map<int, int>> pointMap;
    CountSquares() {
        
    }

    bool isDiagonal(int p, int q, int x, int y) {
        return abs(p-x) == abs(q-y);
    }
    
    void add(vector<int> point) {
        points.push_back(point);
        pointMap[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int px = point[0];
        int py = point[1];
        int ans = 0;

        for(auto& x:pointMap) {
            int p = x.first;
            for(auto& y:pointMap[p]) {
                int q = y.first;

                if(p == px && q == py || !isDiagonal(px, py, p, q))
                    continue;
                
                // check x, py:
                int a = 0;
                if(pointMap[p].find(py) != pointMap[p].end())
                    a = pointMap[p][py];
                
                // check (px, y) & (px, py):
                int b = 0, c = 1;
                if(pointMap.find(px) != pointMap.end()) {
                    if(pointMap[px].find(q) != pointMap[px].end())
                        b = pointMap[px][q];
                    
                    if(pointMap[px].find(py) != pointMap[px].end()) 
                        c = pointMap[px][py];
                }

                // get x, y frequency:
                int d = pointMap[p][q];

                ans += (a*b*c*d);
            }
        }

        return ans;
    }
};
