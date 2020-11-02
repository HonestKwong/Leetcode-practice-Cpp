class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=1;
        if(nums[0]!=nums[1]) return nums[0];
        for(; i<nums.size(); i++){
            if(i == (nums.size()-1)) break;
            if((nums[i]!=nums[i-1]) && (nums[i]!=nums[i+1])) break;
        }
        return nums[i];
    }
};