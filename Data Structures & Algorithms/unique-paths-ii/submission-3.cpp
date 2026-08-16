class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // If the start cell is an obstacle, no paths are possible
        if (obstacleGrid[0][0] == 1) return 0;

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        dp[0][0] = 1; // Base case

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue; // Already set

                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0; // Obstacle
                } else {
                    int top = (i > 0) ? dp[i - 1][j] : 0;
                    int left = (j > 0) ? dp[i][j - 1] : 0;
                    
                    dp[i][j] = top + left;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};