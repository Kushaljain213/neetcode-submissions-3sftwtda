class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        int ans = 0;
        while(left <= right){
            long long mid = left + (right-left)/2;
            if((long long)mid*mid < x){
                ans = mid;
                left = mid+1;
            }
            else if((long long)mid*mid > x){
                right = mid-1;
            }
            else{
                return (int)mid;
            }
        }
        return ans;
    }
};