class Solution {
public:
    int cuttingRope(int n) {
        if(n<=3) return n-1;
        if((n%3)==0) return pow(3,n/3);
        else if ((n%3)==1) return (pow(3,n/3-1)*4);
        return 2*pow(3,n/3);
    }
};