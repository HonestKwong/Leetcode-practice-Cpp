/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // if(strs.size() == 0) return 0;
        unordered_map<string, vector<string>> ans;
        vector<vector<string>> result;
        for(string &temp : strs){  //C++11新特性
            string temp2 = temp;
            sort(temp2.begin(),temp2.end());
            ans[temp2].push_back(temp);
        }
        for(auto&x :ans)
            result.push_back(x.second);
        return result;


        
    }
};
// @lc code=end

