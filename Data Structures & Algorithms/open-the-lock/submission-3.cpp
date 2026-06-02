class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> vis(deadends.begin(),deadends.end());
        if(vis.count("0000")) return -1;
        queue<pair<string,int>> q;
        q.push({"0000",0});
        vis.insert("0000");
        while(!q.empty()){
            auto [str, num] = q.front();
            q.pop();
            if(str == target) return num;
            for(const string& s : func(str)){
                if(!vis.count(s)){
                    vis.insert(s);
                    q.push({s,num+1});
                }
            }
        }
        return -1;
    }
    vector<string> func(string& s){
        vector<string> ans;
        for(int i = 0 ;i < 4 ; i++){
            string temp = s;
            temp[i] = (temp[i]-'0'+1)%10 + '0';
            ans.push_back(temp);
            temp = s;
            temp[i] = (temp[i]-'0'- 1 + 10)%10 + '0';
            ans.push_back(temp);
        }
        return ans;
    }
};