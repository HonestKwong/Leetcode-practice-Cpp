class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        int i = 0;
        int j = matrix[0].size()-1;
        while(i<matrix.size()&&j>=0){
            if(target==matrix[i][j])return true;
            else if(target<matrix[i][j]) j--;
            else if(target>matrix[i][j]) i++;  //这里的else是必须的，不然数组j--后再判断，数组会出界！！！
        }
        return false;
    }
};

class Solution1 {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0){
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int row = m - 1;
        int col = 0;
        while (row >=0 && col < n){
            if(matrix[row][col] < target){
                col += 1;
            }
            else if(matrix[row][col] > target){
                row -= 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};