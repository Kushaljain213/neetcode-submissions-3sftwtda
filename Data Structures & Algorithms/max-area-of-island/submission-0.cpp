class Solution {
private:
    vector<pair<int,int>> dir = {{-1,0},{0,-1},{0,1},{1,0}};
    void dfs(vector<vector<int>>& grid, int r , int c, int& area){
        if(r <0 || c <0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0){
            return;
        }
        grid[r][c] =0;
        area++;
        for(auto[dr,dc] : dir){
            dfs(grid,r+dr,c+dc,area);
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    int area = 0;
                    dfs(grid,i,j,area);
                    ans = max(ans,area);
                }
            }
        }
        return ans;
    }
};
