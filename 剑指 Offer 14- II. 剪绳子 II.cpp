//可以顺便复习快速幂
class Solution {
public:
    int cuttingRope(int n) {
        if(n<=3) return n-1;
        long b = n%3;
        long p = 1000000007;
        long res = 1, x = 3;
        for(int a=n/3-1; a>0; a/=2){
            if(a%2==1) res = (res*x)%p;
            x=(x*x)%p;
        }
        if(b==0) return (int) (res*3%p);
        else if(b==1) return (int)(res*4%p);
        return (int)(res*6%p);
        // if(n%3==0) return int((long long)pow(3,n/3)%(long long)1000000007);
        // else if (n%3==1) return int((long long)pow(3,(n/3)-1)*4%(long long)1000000007);
        // else return int(2*(long long)pow(3,n/3)%(long long)1000000007);
    }
};