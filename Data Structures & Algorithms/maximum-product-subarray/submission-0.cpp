class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,1));
        int ans = nums[0];
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
            ans = max(ans, dp[i][i]);
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                dp[i][j] = dp[i][j-1]*nums[j];
                ans =max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
