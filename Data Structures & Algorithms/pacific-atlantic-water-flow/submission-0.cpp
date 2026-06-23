class Solution {
public:
   vector<vector<int>> ans;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        //creating visited 2-d vectors
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        //run dfs and keep updating nodes that are reachable from the edge, this is the idea of water flowing backwards
        for (int i = 0; i < rows; i++) {
            dfs(i, 0, heights, pacific);          // left edge
            dfs(i, cols - 1, heights, atlantic);  // right edge
        }
        for (int j = 0; j < cols; j++) {
            dfs(0, j, heights, pacific);          // top edge
            dfs(rows - 1, j, heights, atlantic);  // bottom edge
        }

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});

        return ans;
    }

    void dfs(int row, int col, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
        visited[row][col] = true;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int d = 0; d < 4; d++) {
            int nr = row + dr[d], nc = col + dc[d];
            if (nr < 0 || nr >= heights.size() || nc < 0 || nc >= heights[0].size()) continue;
            if (visited[nr][nc]) continue;
            if (heights[nr][nc] < heights[row][col]) continue; // can't flow uphill into here
            dfs(nr, nc, heights, visited);
        }
    }  
};
