class Solution {
public:
    vector<double> twoSum(int n) {
        vector<double> res;
        int dp[11][66] ={0};
        for(int j=0; j<6; j++) dp[0][j] = 1;
        for(int i=1; i<n; i++){
            for(int j=i; j<(i+1)*6; j++){
              for(int k = 1; k<=6; k++){
                  if((j-k)<0) break;
                  dp[i][j] += dp[i-1][j-k];
              }

            }
        }


        // int sum=0;
        // for(int j = n-1; j<6*n; j++)
        //     sum += dp[n-1][j];
        int sum = pow(6,n);
        for(int j = n-1; j<6*n; j++)
            res.push_back(dp[n-1][j]*1.0/sum);
            // res.push_back(dp[n-1][j]);
        return res;
    }

};

// class Solution {
// public:
//     vector<double> twoSum(int n) {
//         int dp[15][70];
//         memset(dp, 0, sizeof(dp));
//         for (int i = 1; i <= 6; i ++) {
//             dp[1][i] = 1;
//         }
//         for (int i = 2; i <= n; i ++) {
//             for (int j = i; j <= 6*i; j ++) {
//                 for (int cur = 1; cur <= 6; cur ++) {
//                     if (j - cur <= 0) {
//                         break;
//                     }
//                     dp[i][j] += dp[i-1][j-cur];
//                 }
//             }
//         }
//         int all = pow(6, n);
//         vector<double> ret;
//         for (int i = n; i <= 6 * n; i ++) {
//             ret.push_back(dp[n][i] * 1.0 / all);
//         }
//         return ret;
//     }
// }; 
