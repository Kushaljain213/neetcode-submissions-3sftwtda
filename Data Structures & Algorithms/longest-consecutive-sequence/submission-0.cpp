class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int i = 0 ; i < nums.size() ; i++){
            st.insert(nums[i]);
        }
        int ans = 0;
        for(auto x : st){
            if(st.find(x-1) == st.end()){
                int length = 1;
                while(st.find(x+length) != st.end()){
                    length++;
                }
                ans = max(ans,length);
            }
        }
        return ans;
    }
};
