class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            if(nums[0] >= target){
                return 1;
            }
            return 0;
        }
        int left = 0;
        int right = 0;
        int sum = 0;
        int ans = INT_MAX;

        while(right < n){
            sum+= nums[right];
            while (sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        if(ans == INT_MAX){
            return 0;
        }
        return ans;
    }
};