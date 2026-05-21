class Solution {
public:

    vector<vector<bool>> vis1;
    vector<vector<bool>> vis2;
    
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};
    int n;
    int m;

    bool isValid(int r, int c){
        return r >= 0 && c >= 0 and r < n and c < m;
    }

    void dfs(vector<vector<int>> graph, vector<vector<bool>> &vis, int row, int col){
        
        vis[row][col] = true;

        for(int i = 0; i < 4; i++){
            int newR = row + dx[i];
            int newC = col + dy[i];

            if(isValid(newR,newC) and graph[newR][newC] >= graph[row][col] and vis[newR][newC] == false){
                dfs(graph, vis, newR, newC);
            }
        }

    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        n = heights.size();
        m = heights[0].size();

        vis1.resize(n, vector<bool>(m, false));
        vis2.resize(n, vector<bool>(m, false));
        vector<vector<int>> ans;

        // top
        for(int c = 0; c < m; c++){
            dfs(heights, vis1, 0, c);
        }

        //left
        for(int r = 0; r < n; r++){
            dfs(heights, vis1, r, 0);
        }

        // bottom
        for(int c = 0; c < m; c++){
            dfs(heights, vis2, n - 1, c);
        }

        //right
        for(int r = 0; r < n; r++){
            dfs(heights, vis2, r, m - 1);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis1[i][j] and vis2[i][j]){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;



    }
};
