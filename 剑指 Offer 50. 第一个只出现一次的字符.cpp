class Solution {
//旨在熟悉unordered_map 的简单用法
public:
    char firstUniqChar(string s) {
        // if (s.size()==0) return {' '};
        unordered_map<char,bool> dict;
        char res;
        for(char &c:s)  dict[c] = dict.find(c) == dict.end();
        for(char &c:s)  if(dict[c]==1) return c;
        return ' ';
    }
};