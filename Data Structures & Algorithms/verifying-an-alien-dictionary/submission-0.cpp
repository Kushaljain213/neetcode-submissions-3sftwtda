class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> mp;
        for(int i = 1; i <= 26 ; i++){
            mp[order[i-1]] = i;
        }
        auto compare  = [&](const string &a , const string &b){
            for(int i = 0 ; i < min(a.size(),b.size()) ; i++){
                if(a[i] != b[i]){
                    return mp[a[i]] < mp[b[i]];
                }
            }
            return a.size() <= b.size();
        };
        return is_sorted(words.begin(),words.end(),compare);
    }
};