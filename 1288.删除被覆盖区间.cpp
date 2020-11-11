/*
 * @lc app=leetcode.cn id=1288 lang=cpp
 *
 * [1288] 删除被覆盖区间
 */

// @lc code=start
bool compare(const vector<int>&a ,const vector<int>&b){
        if(a[0]<=b[0]) return true;
        return false;
    }
class Solution1 {
public:

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int max_right = 0;
        int count = 0;
        for(auto &x : intervals){
            if(x[1]>max_right) max_right = x[1];
            else{
                count++;
            }
        }
        return intervals.size()-count;
    }
};

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int max_right = 0;
        vector<int> toDelete; 
        for(int i=0; i<intervals.size(); i++){
            if(intervals[i][1]>max_right) max_right = intervals[i][1];
            else{
                toDelete.push_back(i);
            }
        }
        for(auto& x:toDelete)
            intervals.erase(intervals.begin()+x);        
        return intervals.size();
    }
};
// @lc code=end

