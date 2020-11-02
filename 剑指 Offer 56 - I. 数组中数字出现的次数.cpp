class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int res = 0;
        for(auto &x:nums) res ^= x;
        int div = 1;
        while((div & res)==0) div<<=1;
        int a = 0; int b =0;
        for(auto &x:nums){
            if(x & div) a ^= x;
            else b ^= x;
        }
        return {a,b};
    }
};