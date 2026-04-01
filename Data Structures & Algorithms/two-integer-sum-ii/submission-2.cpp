class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size()-1;
        vector<int> v(2);
        while(left < right){
            int val = numbers[left]+numbers[right];
            if(val > target){
                right--;
            }
            else if(val < target){
                left++;
            }
            else{
                v[0] = left+1;
                v[1] = right+1;
                return v; 
            }
        }   
        return v;     
    }
};
