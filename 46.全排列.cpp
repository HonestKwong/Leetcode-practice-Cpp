/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (77.09%)
 * Likes:    969
 * Dislikes: 0
 * Total Accepted:    213.1K
 * Total Submissions: 276.5K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmpOrder;
    unordered_set<int> tmpSet;
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums,0);
        return res;
    }

    void backtrack(const vector<int>&nums, int n){
        if(tmpOrder.size() == nums.size()){
            res.push_back(tmpOrder);
            return;
        }
        for(int i=n; i<nums.size(); i++){
            if(tmpSet.find(nums[i])!=tmpSet.end()) continue;
            tmpOrder.push_back(nums[i]);
            tmpSet.insert(nums[i]);
            backtrack(nums, n);
            tmpSet.erase(nums[i]);
            tmpOrder.pop_back();
        }
    }
};
// @lc code=end

