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


class Solution3 {
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

class Solution4 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //这个还是暴力解法，但是比较有意思的是返回值使用的{i,j} 我想是调用了vector的构造函数
        int i;
        int j;
        // vector<int> res;
        for(i=0; i<nums.size()-1; i++){
            for(j = i+1; j<nums.size(); j++){
                if(nums[i]+nums[j] == target){
                    // res.push_back(i);
                    // res.push_back(j);
                    // break;
                    return {i,j};
                }
            }
        }
        return {i,j};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hashmap;
        // 添加使用哈希表的方法，这种方法使用Map并使用count统计是否存在目标值
        //还得试一试双指针方法，其首先排序
        for(int i=0; i<nums.size(); i++){
            hashmap.insert(map<int,int>::value_type(nums[i],i));
        }
        for(int j=0; j<nums.size(); j++){
            if((hashmap.count(target-nums[j]))&&(hashmap[target-nums[j]]!=j)) return {j,hashmap[target-nums[j]]};
        }
        return {};
    }
};
// @lc code=end

