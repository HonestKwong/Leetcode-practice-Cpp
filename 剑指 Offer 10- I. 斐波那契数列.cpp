//注意测试用例和取余的数据类型
class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        long res = 0;
        long a = 0;
        long b = 1;
        for(int i=1; i<n;i++){
            res = (a+b)%1000000007;
            
            a = b;
            b = res;
        }
        return (int)res;
    }
};