class Solution {
public:

    vector<vector<int>> dp;
    int helper(int row, int col, int m, int n){
        if(row >= m or col >= n){
            return 0;
        }

        if(row == m - 1 and col == n - 1){
            return 1;
        
        }

        if(dp[row][col] != -1){
            return dp[row][col];
        }

        return dp[row][col] = helper(row + 1, col, m, n) + helper(row, col + 1, m, n);
    }

    int uniquePaths(int m, int n) {
    
        dp.resize(m, vector<int>(n, -1));
        return helper(0, 0, m, n);
    }
};
