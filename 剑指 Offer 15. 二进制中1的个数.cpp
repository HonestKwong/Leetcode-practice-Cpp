class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        int i = 0;
        while(i<32){
            if(n%2 == 1) res++;            
            n=n/2;
            i++;
        }
        return res;
    }
};