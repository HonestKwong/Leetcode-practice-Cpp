/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 *
 * https://leetcode-cn.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (43.32%)
 * Likes:    693
 * Dislikes: 0
 * Total Accepted:    163.2K
 * Total Submissions: 376.7K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 给出一个区间的集合，请合并所有重叠的区间。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: intervals = [[1,3],[2,6],[8,10],[15,18]]
 * 输出: [[1,6],[8,10],[15,18]]
 * 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2:
 * 
 * 输入: intervals = [[1,4],[4,5]]
 * 输出: [[1,5]]
 * 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 * 注意：输入类型已于2019年4月15日更改。 请重置默认代码定义以获取新方法签名。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * intervals[i][0] <= intervals[i][1]
 * 
 * 
 */

// @lc code=start
bool compare(const vector<int>& a, const vector<int>& b){  //最后使用引用，不然效率太低了
    if(a[0]<b[0]) return true;
    return false;

}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0) return {};
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), compare);
        int left = intervals[0][0];  //base case
        int right = intervals[0][1];
        for(int i = 1; i<intervals.size(); i++){
            if(intervals[i][0]>right){
                res.push_back({left,right});
                left = intervals[i][0];
                right = intervals[i][1];
                }
            if(intervals[i][1]>right){
                right = intervals[i][1];
            }

        }
        res.push_back({left,right});
        return res;

    }
};
// @lc code=end

