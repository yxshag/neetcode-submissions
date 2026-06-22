class Solution {
public:
    int count=0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int max_size = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    dfs(grid, r, c, rows, cols);
                    max_size=max(max_size,count);
                    count=0;
                }
            }
        }

        return max_size;

    }
private:
    void dfs(vector<vector<int>>& grid, int r, int c, int rows, int cols) {
        // out of bounds or water or already visited -> stop
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != 1) {
            return;
        }

        grid[r][c] = 0; // mark as visited
        count+=1;
        // explore all 4 directions
        dfs(grid, r + 1, c, rows, cols);
        dfs(grid, r - 1, c, rows, cols);
        dfs(grid, r, c + 1, rows, cols);
        dfs(grid, r, c - 1, rows, cols);
        
    }        
    
};
