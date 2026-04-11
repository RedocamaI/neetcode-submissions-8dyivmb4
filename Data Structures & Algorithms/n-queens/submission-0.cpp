class Solution {
public:
    vector<int> di = {-1, -1, -1};
    vector<int> dj = {0, -1, 1};
    vector<vector<string>> sol;

    bool isPos(int i, int j, vector<string>& asol) {
        // go top:
        for(int k=i-1;k>=0;k--) {
            if(asol[k][j] == 'Q')
                return false;
        }

        // go left diagonal:
        int x=i-1, y=j-1;
        while(x >= 0 && y >= 0) {
            if(asol[x--][y--] == 'Q')
                return false;
        }

        // go right diagonal:
        x=i-1, y=j+1;
        while(x >= 0 && y < asol.size()) {
            if(asol[x--][y++] == 'Q')
                return false;
        }

        return true;
    }

    void getSolutions(int ind, vector<string>& asol) {
        if(ind == asol.size()) {
            sol.push_back(asol);
            return;
        }

        bool isPlaced = false;
        for(int j=0;j<asol.size();j++) {
            if(!isPos(ind, j, asol))
                continue;

            asol[ind][j] = 'Q';
            getSolutions(ind+1, asol);
            // backtrack:
            asol[ind][j] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> asol;
        for(int i=0;i<n;i++) {
            string row = "";
            for(int j=0;j<n;j++) {
                row += '.';
            }
            asol.push_back(row);
        }

        for(int i=0;i<n;i++) {
            asol[0][i] = 'Q';
            getSolutions(1, asol);
            asol[0][i] = '.';
        }

        return sol;
    }
};
