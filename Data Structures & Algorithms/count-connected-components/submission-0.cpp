class Solution {
public:
    void dfs(vector<vector<int>>& edges, vector<int>& vis, int u){
    vis[u] = 1;
        for(int v : edges[u]){
            if(!vis[v]){
                dfs(edges,vis,v);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjLs(n);
        vector<int> vis(n);
        for(int i = 0 ; i < edges.size() ; i++){
            adjLs[edges[i][0]].push_back(edges[i][1]);
            adjLs[edges[i][1]].push_back(edges[i][0]);
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                dfs(adjLs,vis,i);
                ans++;
            }
        }
        return ans;
    }
};
