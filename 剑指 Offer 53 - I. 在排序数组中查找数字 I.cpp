class Solution {
public:
    int search(vector<int>& nums, int target) {
        // return count(nums.begin(), nums.end(), target);
        if(nums.size()==0) return 0;
        auto ptri = nums.begin();
        auto ptrj = nums.end()-1;
        for(; ptri!=nums.end(); ptri++){
            if(*ptri == target) break;
        }
        for(; ptrj != nums.begin()-1; --ptrj){
            if(*ptrj == target) break;
        }
        if(ptrj-ptri>=0) return ptrj-ptri+1;
        return 0;
    }
};