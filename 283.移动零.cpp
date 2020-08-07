/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution1 {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        int j=0;
        for(i; i<nums.size(); i++){
            if(nums[i]!=0){
                nums[j]=nums[i];
                j++;
            }
        }
        for(j; j<nums.size(); j++) nums[j]=0;
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int cur=0,last =0;cur<nums.size();cur++){
            if(nums[cur]!=0){
                swap(nums[cur],nums[last]);  //关键点在此
                last++;
            }
        }
    }
};
// @lc code=end

