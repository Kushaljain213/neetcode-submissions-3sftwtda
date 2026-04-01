class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = 1;
        vector<int> v(2);
        while(left < numbers.size()-1){
            if((numbers[left] + numbers[right]) == target){
                v[0] = left + 1;
                v[1] = right + 1;
                return v;
            }
            else if((numbers[left] + numbers[right]) > target){
                left++;
                right = left+1;
            }
            else {
                right++;
            }
        }   
        return v;     
    }
};
