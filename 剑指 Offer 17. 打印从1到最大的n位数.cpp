class Solution {
public:
    vector<int> printNumbers(int n) {
        int end = 0;
        vector<int> res;
        for(int i=0;i<n; i++){
            end += 9*pow(10,i);
        }
        for(int i=1;i<=end;i++){
            res.push_back(i);
        }
        return res;
    }
};