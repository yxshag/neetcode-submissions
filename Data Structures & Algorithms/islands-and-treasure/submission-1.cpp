class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> q;

        //push all treasure cells into the queue as sources
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};//neighbors

        //expanding outward from ALL sources at once
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];

                // skip out of bounds, water, or already-visited/finalized cells
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
                if (grid[nr][nc] == -1) continue;
                if (grid[nr][nc] != INT_MAX) continue;  // already has a distance

                grid[nr][nc] = grid[r][c] + 1;
                q.push({nr, nc});//push this as a new source(kind of)
            }
        }
    }
};