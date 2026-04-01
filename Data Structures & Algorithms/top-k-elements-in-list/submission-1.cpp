class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int,greater<int>> freq;
        for(int i = 0 ; i < nums.size() ; i++){
            freq[nums[i]]++;
        }
        vector<pair<int,int>> v(freq.begin(), freq.end());
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });
        vector<int>a;
        for(int i = 0 ; i < k ; i++){
            a.push_back(v[i].first);
        }
        
        return a;
    }
};
