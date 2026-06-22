class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==0){
                dfs(grid,i,j,rows,cols,0);
                }
            }
        }
    }
private:
    void dfs(vector<vector<int>>& grid, int r, int c, int rows, int cols,int dist) {
        // out of bounds or water or treasure
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] < 0) {
            return;
        }
        if (dist > grid[r][c]) {   //stopping condition-if it is not an improvement , stop the path
            return;
        }

        grid[r][c] = dist; // only update if it is the minimum dist

        // explore all 4 directions
        dfs(grid, r + 1, c, rows, cols,dist+1);
        dfs(grid, r - 1, c, rows, cols,dist+1);
        dfs(grid, r, c + 1, rows, cols,dist+1);
        dfs(grid, r, c - 1, rows, cols,dist+1);
    }
};
