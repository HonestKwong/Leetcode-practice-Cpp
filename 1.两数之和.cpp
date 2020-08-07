/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i;
        int j;
        vector<int> res;     //暴力解法，没有技术含量
        int flag=0;
        for(i=0;i<(nums.size()-1);i++){
            for(j=i+1;j<nums.size();j++){
                if((nums[i]+nums[j])==target)
                {
                    res.push_back(i);
                    res.push_back(j);
                    flag = 1;
                    break;
                }
            if(flag==1) break;
            }
        }
        return res;
    }
};

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i;
        int j;
        vector<int> res;   //暴力解法，也没有技术含量复杂度O(n^2),空间S(1)
        for(i=0;i<(nums.size()-1);i++){
            for(j=i+1;j<nums.size();j++){
                if((nums[i]+nums[j])==target)
                {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i;
        int j;
        vector<int> res;   //可以使用双指针、Hash表，先排序再找位置，还未自己完成
        for(i=0;i<(nums.size()-1);i++){
            for(j=i+1;j<nums.size();j++){
                if((nums[i]+nums[j])==target)
                {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }
};
// @lc code=end

