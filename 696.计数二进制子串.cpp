/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 */

// @lc code=start
//自己写的解法，运行速度45.84% 内存11.65%不是很好

//总结 是我把计数的程序写复杂了
class Solution {
public:
    int countBinarySubstrings(string s) {
        if(s.size()<2) return 0;
        vector<int> countNum;
        int count = 0;
        int total = 0;
        for(int i=0; i<s.size(); i++){
            if(i>s.size()-2){
                count++;
                countNum.push_back(count);
                break;
            }
            count++;
            if(s[i]!=s[i+1]){
                countNum.push_back(count);
                count = 0;
            }

        }

        for(int i=0; i<countNum.size()-1; i++){
            total += min(countNum[i],countNum[i+1]);  //应该取最小值，这里写错了
        }
    return total;
    }
};


// 官方题解
class Solution2 {
public:
    int countBinarySubstrings(string s) {
        vector<int> counts;
        int ptr = 0, n = s.size();
        while (ptr < n) {
            char c = s[ptr];
            int count = 0;
            while (ptr < n && s[ptr] == c) {
                ++ptr;
                ++count;
            }
            counts.push_back(count);
        }
        int ans = 0;
        for (int i = 1; i < counts.size(); ++i) {
            ans += min(counts[i], counts[i - 1]);
        }
        return ans;
    }
};

// @lc code=end

