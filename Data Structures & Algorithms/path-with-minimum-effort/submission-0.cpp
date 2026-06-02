class Solution {
public:
    vector<pair<int,int>> dir = {{-1,0},{0,-1},{0,1},{1,0}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        //pq = (effort,row,col);
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        pq.push({0,0,0});
        dist[0][0] = 0;
        while(!pq.empty()){
            auto [effort,r,c] = pq.top();
            pq.pop();
            if(r==n-1 && c==m-1) return effort;
            if(effort > dist[r][c]) continue;
            for(auto [dr,dc] : dir){
                int nr = r+dr;
                int nc = c+dc;
                if(nr>=0 && nr < n && nc>=0 && nc < m){
                    int val = max(effort,abs(heights[nr][nc] - heights[r][c]));
                    if(val < dist[nr][nc]){
                        dist[nr][nc] = val;
                        pq.push({val,nr,nc});
                    }
                }
            }
        }
        return 0;
    }
};