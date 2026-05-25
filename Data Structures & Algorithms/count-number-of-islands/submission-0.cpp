class Solution {
public:

    vector<vector<bool>> vis;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};


    bool isValid(int r, int c, int m, int n){
        return r >= 0 and c >= 0 and r < m and c < n;
    }

    void dfs(vector<vector<char>>& grid, int row, int col, int m, int n){

        vis[row][col] = 1;

        for(int i = 0; i < 4; i++){
            
            int n_row = row + dx[i];
            int n_col = col + dy[i];

            if(isValid(n_row, n_col, m, n) && vis[n_row][n_col] == false
            && grid[n_row][n_col] != '0'){
                dfs(grid, n_row, n_col, m, n);
            }   
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;
        vis.resize(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != '0' and vis[i][j] == false){
                    dfs(grid, i, j, m, n);
                    ans += 1;
                }
            }
        }    

        return ans;
    }
};
