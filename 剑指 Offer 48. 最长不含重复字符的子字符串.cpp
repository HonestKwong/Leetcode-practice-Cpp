class Solution {
public:
//这道题和第三题相同，但是我每次都写出了不同的解法
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        if(s.size() == 1) return 1;
        unordered_map<char,int> tmp;
        int j = 0;
        int res = 0;
        for(int i=0; i<s.size(); i++){
            auto search = tmp.find(s[i]);
            if(search != tmp.end()){
                j = max(j, search->second+1);
                tmp.erase(search);
                tmp.insert({s[i],i});
                res = max(res, i-j+1);
                continue;
            }
            tmp.insert({s[i],i});
            res = max(res, i-j+1);
        } 
        return res;
    }
};