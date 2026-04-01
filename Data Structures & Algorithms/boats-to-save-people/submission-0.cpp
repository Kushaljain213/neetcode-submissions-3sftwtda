class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int mx = *max_element(people.begin(),people.end());
        vector<int> count(mx+1,0);
        for(int p : people){
            count[p]++;
        }
        int i=1;
        for(int idx = 0; idx < people.size(); idx++){
            while(count[i] == 0){
                i++;
            }
            people[idx] = i;
            count[i]--;
        }
        int ans = 0;
        int left = 0, right = people.size()-1;
        while(left <= right){
            int val = limit - people[right];
            right--;
            ans++;
            if(left <= right && val >= people[left]){
                left++;
            }
        }
        return ans;
    }
};