class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int n = nums.size();
        int val = 0;
        for(int i = 0 ; i < n ; i++){
            val += nums[i];
            ans = max(ans,val);
            if(val < 0){
                val = 0;
            }
        }
        return ans;
    }

};
