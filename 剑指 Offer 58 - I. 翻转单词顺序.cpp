class Solution {
public:
    string reverseWords(string s) {
        stack<string> tmp;
        string tmp2;
        string res;
        for(int i=0; i<s.size(); i++){
            
            if(s[i] == ' ') {
                if(!tmp2.empty()){
                    tmp.push(tmp2);
                    tmp2.clear();
                }
                continue;                
            }
            if(s[i]!=' ')
                tmp2+=s[i];
        }
        if(!tmp2.empty()){
            tmp.push(tmp2);
            tmp2.clear();
            }
        // for(int i=1;i<=tmp.size(); i++){
        //     if(i<(tmp.size()-1)){
        // res.clear();
        while(!tmp.empty()){
                res+=tmp.top();
                res+=' ';
                tmp.pop();
        }
        res.pop_back();

        return res;
    }

    
};