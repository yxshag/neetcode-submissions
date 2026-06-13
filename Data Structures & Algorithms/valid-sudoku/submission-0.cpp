class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_map<char,int>> row;
        unordered_map<int,unordered_map<char,int>> col;
        unordered_map<int,unordered_map<char,int>> squ;
        for(int i=0;i<board[0].size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){continue;}
                if((row[i][board[i][j]]==1||col[j][board[i][j]]==1||squ[(i/3)*3+(j/3)][board[i][j]]==1)){return false;}
                row[i][board[i][j]]+=1;
                col[j][board[i][j]]+=1;
                squ[(i/3)*3+(j/3)][board[i][j]]+=1;
            }
        }

        return true;
    }
};
