
//自己写的题解，速度和内存都很一般124 ms, 在所有 C++ 提交中击败了38.31%的用户
//28.1 MB,在所有 C++ 提交中击败了16.88%的用户
class Solution1 {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> ans;
        for(int i=0; i<nums.size();i++)
        {
            if(ans.find(nums[i])!=ans.end()) return nums[i];
            ans.insert(nums[i]);
        }
        return 0;
    }
};

//