class Solution {
public:
    bool checkCol(vector<vector<char>>& b){
        for(int j=0;j<9;j++){
            vector<int> cnt(9, 0);
            for(int i=0;i<9;i++){
                cnt[b[i][j]-'0'-1]++;
            }

            for(int i=0;i<9;i++){
                if(cnt[i] > 1)  return false;
            }
        }

        return true;
    }

    bool checkRow(vector<vector<char>>& b){
        for(int i=0;i<9;i++){
            vector<int> cnt(9, 0);
            for(int j=0;j<9;j++){
                cnt[b[i][j]-'0'-1]++;
            }

            for(int i=0;i<9;i++){
                if(cnt[i]  > 1) return false;
            }
        }

        return true;
    }

    bool checkGrid(vector<vector<char>>& brd){
        for(int a=0;a<9;a+=3){
            for(int b=0;b<9;b+=3){
                vector<int> cnt(9, 0);
                for(int i=a;i<a+3;i++){
                    for(int j=b;j<b+3;j++){
                        cnt[brd[i][j]-'0'-1]++;
                    }
                }

                for(int i=0;i<9;i++){
                    if(cnt[i] > 1)  return false;
                }
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        bool isColValid = checkCol(board);
        if(!isColValid) return false;
        
        bool isRowValid = checkRow(board);
        if(!isRowValid) return false;
        
        bool isGridValid = checkGrid(board);
        
        return isGridValid;
    }
};
