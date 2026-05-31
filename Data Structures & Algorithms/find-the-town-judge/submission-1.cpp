class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> v1(n+1), v2(n+1);
        for(int i = 0 ; i < trust.size() ; i++){
            v1[trust[i][1]]++;
            v2[trust[i][0]]++;
        }
        for(int i = 1 ; i <= n ; i++){
            if(v2[i] == 0 && v1[i] == n-1){
                return i;
            }
        }
        return -1;
    }
};