class Solution {
public:
//错误的思路
    string minNumber(vector<int>& nums) {
        string res;
        for(int i=0; i<nums.size(); i++) res += to_string(nums[i]);
        sort(res.begin(),res.end());
        
        for(int i=0; i<res.size(); i++){
            if(res[i] != '0'){
                swap(res[i],res[0]);
                break;
            }
        }
        return res;

    }
};


class Solution {
public:

//正解，很有精神！使用算法适配器。构建二元谓词~
    static bool compare(string a, string b){
        return (std::stol(a+b)<std::stol(b+a));   //stol 转化为long型
    }
    string minNumber(vector<int>& nums) {
        vector<string> tmp;
        string res;
        for(int i=0; i<nums.size(); i++) tmp.push_back(to_string(nums[i]));
        sort(tmp.begin(),tmp.end(),compare);
        for(string& x : tmp) res += x;
        return res;
    }
};