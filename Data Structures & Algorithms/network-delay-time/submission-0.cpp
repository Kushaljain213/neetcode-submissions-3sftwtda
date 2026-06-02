class Solution {
public:
    vector<pair<int,int>> dir = {{-1,0},{0,-1},{0,1},{1,0}};
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n,INT_MAX);
        int m = times.size();
        vector<pair<int,int>> adjLs[n];
        k--;
        for(int i = 0 ; i < m ; i++){
            adjLs[times[i][0]-1].push_back({times[i][1]-1,times[i][2]});
        }
        dist[k] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto [time, u] = pq.top();
            pq.pop();
            if(time > dist[u]) continue;
            for(auto [v,w] : adjLs[u]){
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    pq.push({dist[u]+w,v});
                }
            }
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};
