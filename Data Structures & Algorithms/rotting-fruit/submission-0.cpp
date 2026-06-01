class Solution {
public:
    vector<pair<int,int>> dir = {{-1,0},{0,-1} , {0,1} , {1,0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<tuple<int,int,int>> q;
        int fresh = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    q.push({i,j,0});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        int mn = 0;
        while(!q.empty()){
            auto [r,c,t] = q.front();
            q.pop();
            mn = max(mn,t);
            for(auto [dr,dc] : dir){
                int nr = r+dr;
                int nc = c+dc;
                if(nr >= 0  && nr <n && nc>=0 && nc < m && grid[nr][nc]==1){
                    q.push({nr,nc,t+1});
                    grid[nr][nc] = 2;
                    fresh--;
                }
            }
        }
        if(fresh > 0) return -1;
        return mn;
    }
};
