class Solution1 {
    //这个方法很拉跨
public:
    double myPow(double x, int n) {
        if(x==0) return 0;
        if(n==0) return 1;
        if(n<0){
            x = 1/x;
            n = -n;
        }
        if(n==1) return x;
        int i = 1;
        double res = 1;
        if(n<0){
            x = 1/x;
            n = -n;
        }
        while(i<n){
            if(i==1) res = x;
            if(i>1073741823|| 2*i>n ){
                res*=x;
                i++;
            }
            else{
                res = res*res;
                i *= 2;
            }
        }
        return res;
    }
};

//使用快速幂运算
class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0) return 0;
        long b = n;
        double res = 1.0;
        if(b < 0) {
            x = 1 / x;
            b = -b;
        }
        while(b > 0) {
            if((b & 1) == 1) res *= x;
            x *= x;
            b >>= 1;
        }
        return res;
    }
};

