class Solution {

private:
    vector<bool> vis;
public:

    void dfs(int src, vector<int> adj[]){
        
        vis[src] = true;

        for(auto &child: adj[src]){
            if(vis[child] == false){
                dfs(child, adj);
            }
        }

    }

    int countComponents(int n, vector<vector<int>>& edges) {

        int ans = 0;
        vis.resize(n, false);
        vector<int> adj[n];

        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        for(int i = 0; i < n; i++){
            if(vis[i] == false){
                dfs(i, adj);
                ans++;
            }
        }

        return ans;
    }
};
