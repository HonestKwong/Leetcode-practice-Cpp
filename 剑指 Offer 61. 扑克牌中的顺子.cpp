class Solution {
public:
    bool isStraight(vector<int>& nums) {
        const int len = nums.size();
        // int numZero = count(nums.begin(), nums.end(), 0);
        // int a = min(nums.begin)
        int countZore = 0;
        int minNum = 0;
        int maxNum = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<len; i++){
            if(nums[i] == 0){
                countZore++;
                continue;
            }
            else if(i == 0 || (nums[i-1]==0 && nums[i]!=0)) {
                minNum = nums[i];
            }
            else if(i!=0 && ((nums[i]-nums[i-1])==0)) return false;
        }
        maxNum = nums[len-1];
        if((maxNum-minNum+1)<=len)
            return true;
        return false;

    }
};