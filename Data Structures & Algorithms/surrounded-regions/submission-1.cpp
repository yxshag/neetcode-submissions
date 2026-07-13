class Solution {
public:
    void solve(vector<vector<char>>& board) {
        //run the dfs for top and bottom rows, as those are the safe rows
        for(int i=0;i<board.size();i++){
            dfs(board,i,0);
            dfs(board,i,board[0].size()-1);
        }
        //also run dfs for left and right cols, as they are also safe cols
        for(int j=1;j<board[0].size()-1;j++){
            dfs(board,0,j);
            dfs(board,board.size()-1,j);
        }
        //update the safe cells to O and unsafe cells to X
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O'){board[i][j]='X';}
                else if(board[i][j]=='Y'){board[i][j]='O';}
            }
        }
    }
    //does dfs from a safe cell and converts every connected cell to safe cell
    void dfs(vector<vector<char>>& board, int i,int j){
        if(i>=board.size()||i<0||j>=board[0].size()||j<0){return;}
        if(board[i][j]=='O'){
            board[i][j]='Y';
            dfs(board, i+1,j);
            dfs(board, i-1,j);
            dfs(board, i, j+1);
            dfs(board, i, j-1);
        }
        return;
    }
};
