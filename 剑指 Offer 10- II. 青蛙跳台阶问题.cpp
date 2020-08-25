class Solution1 {
public:
    //这方法会超时
    int numWays(int n) {
        if(n<=1) return 1;
        if (n<3) return 2;
        return (numWays(n-1)+numWays(n-2));
    }
};

class Solution {
public:
    //使用动态规划
    int numWays(int n) {
        int q = 0, p = 1, temp;
        for(int i = 1; i<=n; i++){
            temp = q;
            q = p;
            p = (temp + p)%1000000007;
        }
        return p;
    }
};