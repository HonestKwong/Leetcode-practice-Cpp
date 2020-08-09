/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0; //首先排除空的字符串
        unordered_set<char> lookup;
        int maxStr = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++){
            while(lookup.find(s[i])!=lookup.end()){
                lookup.erase(s[left]);
                left++;
            }
            maxStr = max(maxStr, i-left+1);
            lookup.insert(s[i]);
        }
        return maxStr;

    }
};

//Solution 1 默写
class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int left = 0;
        int maxNumber = 0;
        unordered_set<char> lookup; //哈希表？
        for(int i = 0; i < s.size(); i++){
            while(lookup.find(s[i]) != lookup.end()){
                lookup.erase(s[left]); //这里注意移除最左的元素，我写成了移除s[i]
                left++;
            }
            lookup.insert(s[i]);
            maxNumber = max(maxNumber, i-left+1);
        }
        return maxNumber;
    }
};

class Solution {
public:
//这中方法与前面一种不一样，我愿称之为绝妙
    int lengthOfLongestSubstring(string s) {
        //s[start,end) 前面包含 后面不包含
        int start(0), end(0), length(0), result(0);
        int sSize = int(s.size());
        vector<int> vec(128, -1);  //初始化一个长度为128的数组，每一位代表一个字符，用以记录出现的位置
        while (end < sSize)
        {
            char tmpChar = s[end];
            //仅当s[start,end) 中存在s[end]时更新start
            if (vec[int(tmpChar)] >= start) //这个字符再次出现
            {
                start = vec[int(tmpChar)] + 1;  //记录到某字符的下一个位置
                length = end - start;
            }
            vec[int(tmpChar)] = end;

            end++;
            length++;
            result = max(result, length);
        }
        return result;
    }
};

// @lc code=end

