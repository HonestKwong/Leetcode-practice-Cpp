class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        // vector<vector<int>> res;
        // int tmp = target/2 + 1;
        // int j = tmp;
        // int i = 1;
        // for(; i<tmp; i++){
        //     for(; j>i; j--){
        //         if(target == ((i+j) * (j-i+1) / 2)){
        //             vector<int> tmp2;
        //             for(int a = i; a<=j; a++){
        //                 tmp2.push_back(a);
        //             }
        //             res.push_back(tmp2);
        //             break;
        //         }
        //         else if(i==j) break;
        //     }
        //     j = tmp;
        // }  
        // return res;

    //     vector<vector<int>> res;
    //     const int tmp = target/2 + 1;
    //     int j = tmp;
    //     int i = tmp-1;
    //     int count = 0;
    //     for(; j>0; j--){
    //         for(; i>0; i--){
    //             if(target == ((i+j) * (j-i+1) / 2)){
    //                 vector<int> tmp2;
    //                 for(int a = i; a<=j; a++){
    //                     tmp2.push_back(a);
    //                 }
    //                 res.push_back(tmp2);
    //                 count++;
    //                 break;
    //             }
    //             else if(i==j) break;
    //         }
    //         i = j - count;
            
    //     }  
    //     return res;

        vector<vector<int>> res;
        int i=1;
        int j=1;
        int sum = 0;
        while(i<=target/2){
            if(sum<target){
                sum += j;
                j++;
            }
            else if(sum>target){
                sum -= i;
                i++;
            }
            else{
                
                vector<int> tmp2;
                for(int a = i; a<j; a++){
                    tmp2.push_back(a);
                }
                res.push_back(tmp2);
                sum -= i;
                i++;
            }
        }
        return res;
    }

};