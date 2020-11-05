/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;
        int resLeft = -1;
        int resRight = -1;
        //搜索左边界
        while(left<=right){
            mid = left + (right-left)/2;
            if(nums[mid] == target) right = mid-1;  //这里我第一遍写错了
            else if(nums[mid] < target) left = mid+1;
            else if(nums[mid] > target) right = mid-1;
        }
        if(left == nums.size() || nums[left]!=target)
            return{-1,-1};
        else
            resLeft = left;

        left = 0;
        right = nums.size()-1;
        while(left<=right){
            mid = left + (right-left)/2;
            if(nums[mid] == target) left = mid+1;
            else if(nums[mid] > target) right = mid-1;
            else if(nums[mid] < target) left = mid+1;
        }
        resRight = right;
        return {resLeft, resRight};
    }
};
// @lc code=end

