class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int res = nums[0];
        if (nums.size()==0) return NULL;
        if(nums.size()==1) return nums[0];
        for(int i = 1; i<nums.size(); i++){
            if(nums[i-1]>0) nums[i] = nums[i-1] + nums[i];
            res = max(res, nums[i]);
        }
        return res;
    }
};