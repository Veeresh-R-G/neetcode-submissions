class Solution {
public:

    vector<vector<int>> dp;

    int helper(vector<vector<int>>& grid, int row, int col){
        if(row >= grid.size() || col >= grid[0].size()){
            return INT_MAX;
        }

        if(row == grid.size() - 1 and col == grid[0].size() - 1){
            return grid[row][col];
        }

        if(dp[row][col] != -1){
            return dp[row][col];
        }

        int bottom = helper(grid, row + 1, col);
        int right = helper(grid, row, col + 1);
        return dp[row][col] = grid[row][col] + min(bottom, right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        dp.resize(n, vector<int>(m, -1));
        return helper(grid, 0, 0);
    }
};