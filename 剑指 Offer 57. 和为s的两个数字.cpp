class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // unordered_set<int> tmp;
        // for(int i=0; i<nums.size(); i++)
        //     tmp.insert(nums[i]);
        // int a = 0;
        // for(int i=0; i<nums.size(); i++){
        //     if(tmp.find(target-nums[i])!=tmp.end()){
        //         a = nums[i];
        //         break;
        //     }
        // }
        // return {a, target-a};
        int i = 0;
        int j = nums.size()-1;
        while(i<j){
            if((nums[i]+nums[j])==target) break;
            else if((nums[i]+nums[j])>target) j--;
            else if((nums[i]+nums[j])<target) i++;
        }
        return{nums[i],nums[j]};
    }
};