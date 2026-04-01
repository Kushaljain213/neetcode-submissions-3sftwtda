class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;
        int ans = 0;
        while(left < right){
            int val = (right-left)*(min(heights[left],heights[right]));
            ans = max(ans,val);
            if(heights[left] < heights[right]){
                left++;
            }
            else if(heights[left] > heights[right]){
                right--;
            }
            else{
                left++;
                right--;
            }
        }
        return ans;
    }
};
