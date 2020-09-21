class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int tmp = 0;
        int vote = 0;
        for(int i=0; i<nums.size(); i++){
            if(tmp == nums[i]){
                vote++;
            }
            else if(vote == 0){
                tmp = nums[i];
                vote++;
            }
            else vote--;
        }
        return tmp;
    }
};