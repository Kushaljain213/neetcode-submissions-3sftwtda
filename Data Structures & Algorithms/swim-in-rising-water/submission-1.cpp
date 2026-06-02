class Solution {
public:
    vector<pair<int,int>> dir = {{-1,0},{0,-1},{0,1},{1,0}};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        // pq({level,row,col})
        dist[0][0] = grid[0][0];
        pq.push({dist[0][0],0,0});
        while(!pq.empty()){
            auto [level , r , c] = pq.top();
            pq.pop();
            if(r == n-1 && c == m-1) return dist[r][c];
            if(level > dist[r][c]) continue;
            for(auto[dr,dc] : dir){
                int nr = r+dr;
                int nc = c+dc;
                if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                    int newLevel = max(level,grid[nr][nc]);
                    if(newLevel < dist[nr][nc]){
                        dist[nr][nc] = newLevel;
                        pq.push({dist[nr][nc] , nr , nc});
                    }
                }
            }
        }
        return -1;
    }
};
