class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int val = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(auto x : nums){
            val += x;
            int diff = val-k;
            ans += mp[diff];
            mp[val]++;
        }
        return ans;
    }
};