class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int n = prices.size();
        int val = 0;
        int ans = INT_MIN;
       for(int right = 0; right < n ; right++){
            if(prices[right] < prices[left]){
                left = right;
            }
            else{
                val = prices[right] - prices[left];
                ans = max(ans,val);
            }
       }
       if(ans == INT_MIN){
        return 0;
       }
       return ans;

    }
};
