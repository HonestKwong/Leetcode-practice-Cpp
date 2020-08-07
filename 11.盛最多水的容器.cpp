/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int temp = 0;
        int area = 0;
        while(i!=j){
            if(height[i]>height[j]){
                temp = height[j]*(j-i);
                if(temp>area) area = temp;   //可以使用max函数
                j--;
            }
            else {
                temp = height[i]*(j-i);
                if(temp>area) area = temp;
                i++;
            }
        }
        return area;
    }
};
// @lc code=end

