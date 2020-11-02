class Solution {
public:
    int strToInt(string str) {
        int res = 0;
        bool flag = 0;
        bool flag2 = 1;
        for(auto &x :str){
            if(flag2 && x==' ')
                continue;
            
            else if (flag2 && (x == '-' || x == '+')) {
                flag2 = 0;
                flag = (x=='-');
                continue;
            }
            if(flag2 && (x<'0'||x>'9')) return 0;
            else if(x==' ') break;
            if(x>'9' || x<'0') break;
            if((res>(INT_MAX/10))|| (res==(INT_MAX/10))&& (x-'0')>7){
                return flag ? INT_MIN : INT_MAX;
            } 
            res = res * 10 + (x - '0');
            flag2 = 0;
        }
        return  flag ? -res : res;

    }
};