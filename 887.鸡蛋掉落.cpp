/*
 * @lc app=leetcode.cn id=887 lang=cpp
 *
 * [887] 鸡蛋掉落
 */

// @lc code=start
class Solution1 {
    //这个算法超时了，非常难
public:
    map<pair<int, int>,int> memo;
    int res = INT_MAX/2;
    int dp(int K, int N){        
        pair<int ,int> tmp = {K,N};
        if(K==1) return N;
        if(N==0) return 0; ///这个地方一开始写错了
        if(memo.find(tmp)!=memo.end())
            return memo[tmp];
        
        for(int i = 1; i<N+1; i++)
            res = min(res,
            max(
                dp(K,N-i),
                dp(K-1,i-1)
                )+1
                );
            // tmp = {K,N};
        memo[tmp] = res;
        return res;
    }
    int superEggDrop(int K, int N) {
        return dp(K,N);
        // return INT_MAX/2;
    }
};

class Solution2 {
public:
    //上面的算法加上二分搜索+但是下面的map是一大败笔
    map<pair<int, int>,int> memo;
    
    // int broken = 0;
    // int no_broken = 0;
    int dp(int K, int N){        
        pair<int ,int> tmp = {K,N};
        if(K==1) return N;
        if(N==0) return 0; ///这个地方一开始写错了
        if(memo.find(tmp)!=memo.end())
            return memo[tmp];
        int low = 1, high = N;
        int res = INT_MAX;
        while(low<=high){
            int mid = (low+(high-low)/2);
            int broken = dp(K-1, mid-1);
            int no_broken = dp(K,N-mid);
            if(broken>no_broken){
                high = mid-1;
                res = min(res, broken+1);
            }
            else{
                low = mid+1;
                res = min(res, no_broken+1);
            }
        //     else {
        //         res = min(res, no_broken+1);
        //         break;
        //         }
        // }
        memo[tmp] = res;
        return res;
    }
    int superEggDrop(int K, int N) {
        return dp(K,N);
        // return INT_MAX/2;
    }
};

class Solution {
public:
    //上面的算法加上二分搜索
    // map<pair<int, int>,int> memo;
    unordered_map<int, int> memo; //在这里map 比 unordered_map快一倍
    
    // int broken = 0;
    // int no_broken = 0;
    int dp(int K, int N){        
        int tmp = N*100 + K ;
        if(K==1) return N;
        if(N==0) return 0; ///这个地方一开始写错了
        if(memo.find(tmp)!=memo.end())
            return memo[tmp];
        int low = 1, high = N;
        int res = INT_MAX;
        while(low<=high){
            int mid = (low+(high-low)/2);
            int broken = dp(K-1, mid-1);
            int no_broken = dp(K,N-mid);
            if(broken>no_broken){
                high = mid-1;
                res = min(res, broken+1);
            }
            else{
                low = mid+1;
                res = min(res, no_broken+1);
            }
        //     else {
        //         res = min(res, no_broken+1);
        //         break;
        //         }
        }
        memo[tmp] = res;
        return res;
    }
    int superEggDrop(int K, int N) {
        return dp(K,N);
        // return INT_MAX/2;
    }
};
// @lc code=end

