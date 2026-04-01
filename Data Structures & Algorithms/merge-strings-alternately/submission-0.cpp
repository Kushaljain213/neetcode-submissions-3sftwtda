class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s = "";
        int l1 = word1.length();
        int l2 = word2.length();
        if(l1>l2){
            for(int i = 0 ; i < l2 ; i++){
                s += word1[i];
                s += word2[i];
            }
            for(int i = l2; i < l1 ; i++){
                s+=word1[i];
            }
        }
        else if(l1 < l2){
            for(int i = 0 ; i < l1 ; i++){
                s += word1[i];
                s += word2[i];
            }
            for(int i = l1; i < l2 ; i++){
                s+=word2[i];
            }
        }
        else{
            for(int i = 0 ; i < l2 ; i++){
                s += word1[i];
                s += word2[i];
            }
        }
        return s;
    }
};