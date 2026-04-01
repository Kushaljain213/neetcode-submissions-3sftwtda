class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int ans = 0;
        vector<int>v;
        for(int i = 0 ; i  < n ; i++){
            if(nums[i] != val){
                v.push_back(nums[i]);
            }
            else{
                ans++;
            }
        }
        for(int i = 0 ; i < n-ans ; i++){
            nums[i] = v[i];
        }
        return n - ans;
    }
};