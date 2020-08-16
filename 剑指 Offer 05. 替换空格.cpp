//时间100  空间16%  改掉一个函数体 变成49.3%
class Solution {
public:
    string replaceSpace(string s) {
        vector<char> temp;
        string ans;
        for(int i=0; i<s.size(); i++){
            if(s[i]==' '){
                temp.push_back('%');
                temp.push_back('2');
                temp.push_back('0');
            }
            else temp.push_back(s[i]);
        }
        for(int i = 0; i<temp.size(); i++){
            ans+=temp[i];
        }
        return ans;
    }
};