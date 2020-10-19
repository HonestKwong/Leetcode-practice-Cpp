class Solution {
public:
//自己写的“分治法” 效率居然100%
    int recur(string& tmp, int n){
        if(n == 0) return 1;  //这里n==0 不是代表只有一位，而是代表有两位，可以表达为(n+2) == 2
        if(n == 1) return 1;
        if(((tmp[n-1]-'0')+(tmp[n-2]-'0')*10)<=25 && ((tmp[n-1]-'0')+(tmp[n-2]-'0')*10)>=10)
            return recur(tmp, n-1)+recur(tmp, n-2);
        else return recur(tmp, n-1);
    }
    int translateNum(int num) {
        string tmp = to_string(num);
        int n = tmp.size();
        if(n==0) return 0; //直接判断为0，避免和下面迭代冲突
        return recur(tmp, n);
    }
};

class Solution {
public:
    int translateNum(int num) {
        string src = to_string(num);
        int p = 0, q = 0, r = 1;
        for (int i = 0; i < src.size(); ++i) {
            p = q; 
            q = r; 
            r = 0;
            r += q; //f(n-1)
            if (i == 0) {  //对0特殊判断
                continue;
            }
            auto pre = src.substr(i - 1, 2);
            if (pre <= "25" && pre >= "10") {
                r += p; //f(n-2)
            }
        }
        return r;
    }
};