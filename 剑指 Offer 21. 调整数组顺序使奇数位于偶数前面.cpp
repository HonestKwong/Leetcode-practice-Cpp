class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        vector<int> ood;
        vector<int> even;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2) ood.push_back(nums[i]);
            else even.push_back(nums[i]);
        }
        ood.insert(ood.end(),even.begin(),even.end());
        return ood;
    }
};