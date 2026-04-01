class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        int n = nums.size();
        for(int i = 0 ; i < n; i++){
            if(nums[i] == 0){
                cnt0++;
            }
            else if(nums[i] == 1){
                cnt1++;
            }
            else{
                cnt2++;
            }
        }
        for(int i = 0 ; i < n; i++){
            if(i < cnt0){
                nums[i] = 0;
            }
            else if( i < (cnt0 + cnt1)){
                nums[i] = 1;
            }
            else{
                nums[i] = 2;
            }
        }
        cout << "[";
        for(int i = 0 ; i < n-1; i++){
            cout << nums[i] << ",";
        }
        cout <<nums[n-1] << "]";
    }
};