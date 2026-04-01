class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_map<char,int>mp;
        int left = 0;
        int right = 0;
        while(right < s.size()){
            if(mp.find(s[right]) != mp.end()){
                left = max(mp[s[right]] + 1, left);
            }
            mp[s[right]] = right;
            ans = max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};
