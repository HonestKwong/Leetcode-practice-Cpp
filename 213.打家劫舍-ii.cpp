/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        return max(robrange(nums, 0, n-2), robrange(nums, 1, n-1));

    }
    int robrange(vector<int>& nums, int start, int end) {

        // vector<vector<int>> dp(n, vector<int>(2,0));
        // dp[0][0] = 0;
        // dp[0][1] = nums[0];
        int dpi_0 = 0;
        int dpi_1 = nums[start];
        int tmp = 0;
        for(int i=start+1; i<=end; i++){
            tmp = dpi_0;
            dpi_0=max(dpi_0, dpi_1);
            dpi_1 = tmp + nums[i];
        }
        return max(dpi_0, dpi_1);
    }
};
// @lc code=end

