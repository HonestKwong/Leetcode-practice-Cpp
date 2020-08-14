/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    int calculateSum(int n){
        int sum = 0;
        int temp=0;
        //下面这段循环是我写的有问题，8月14日还未发现问题
        // while(n/10!=0)
        // {
        //     temp = n%10;
        //     sum += pow(temp,2);
        //     n = n/10;
        //     if(n<10){
        //         sum+=pow(n,2);
        //         break;
        //     }
        // }
        while(n){
            sum += pow(n%10,2);
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> ans;
        while(n!=1){
            if(ans.find(n)!=ans.end()){
                return false;
            }
            else
            {
                ans.insert(n);
                n = calculateSum(n); 
            }   
        }
        return true; 
    }
};
// @lc code=end

