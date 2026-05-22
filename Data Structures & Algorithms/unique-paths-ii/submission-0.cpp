class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<vector<int>>& grid, int row, int col, int m, int n){
        if(row >= m or col >= n or grid[row][col] == 1){
            return 0;
        }

        if(row == m - 1 and col == n - 1){
            return 1;
        
        }

        if(dp[row][col] != -1){
            return dp[row][col];
        }

        return dp[row][col] = helper(grid, row + 1, col, m, n) + helper(grid, row, col + 1, m, n);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        dp.resize(m, vector<int>(n, -1));

        return helper(obstacleGrid, 0, 0, m, n);
    }
};