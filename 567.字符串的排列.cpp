/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 *
 * https://leetcode-cn.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (37.68%)
 * Likes:    193
 * Dislikes: 0
 * Total Accepted:    46.2K
 * Total Submissions: 122.6K
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
 * 
 * 换句话说，第一个字符串的排列之一是第二个字符串的子串。
 * 
 * 示例1:
 * 
 * 
 * 输入: s1 = "ab" s2 = "eidbaooo"
 * 输出: True
 * 解释: s2 包含 s1 的排列之一 ("ba").
 * 
 * 
 * 
 * 
 * 示例2:
 * 
 * 
 * 输入: s1= "ab" s2 = "eidboaoo"
 * 输出: False
 * 
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 输入的字符串只包含小写字母
 * 两个字符串的长度都在 [1, 10,000] 之间
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> need, window;
        int left = 0;
        int right = 0;
        int valid = 0;
        for(auto &c:s1) need[c]++;
        while(right< s2.size()){
            char c = s2[right];
            right++;
            if(need.count(c)){
                window[c]++;
                if(window[c] == need[c]) valid++;
                // else if(window[c] > need[c]) {
                //     valid = 0;
                //     window.clear();  //清楚所有的
                //     window[c]++;
                //     if(window[c] == need[c]) valid++;
                // }
            }
            else{  //直接清空
                valid = 0;
                window.clear();
                left = right;
            }
            while(right-left>=s1.size()){
                char d = s2[left];
                left++;
                if(valid  == need.size()) return true; 
                if(need.count(d)){
                    if(window[d]==need[d]) valid--;
                    window[d]--;
                }
            }
            
        }
        return false;
    }
};
// @lc code=end

