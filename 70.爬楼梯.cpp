/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
//这种方法会超时
class Solution1 {
public:
    int climbStairs(int n) {
        if(n<=1) return 1;
        if(n<3) return 2;
        return climbStairs(n-1)+climbStairs(n-2);
    }
};

//这种方法叫动态规划
class Solution {
public:
    int climbStairs(int n) {
        // if(n<=1) return 1;
        int p = 0;
        int q = 1;
        int temp;
        for(int i=1; i<=n; i++){
            temp = p;
            p = q; 
            q = temp+q;           
        }
        return q;
    }
};
// @lc code=end

