// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         if(nums.size() == 0) return {};
//         deque<int> win;
//         vector<int> res;
//         for(int i=0; i<k; i++) win.push_back(nums[i]);
//         auto max_tmp = max_element(win.begin(), win.end());
//         res.push_back(*max_tmp);
//         for(int i =1; i<nums.size()-k+1; i++){
//             win.pop_front();
//             win.push_back(nums[i+k-1]);
//             max_tmp = max_element(win.begin(), win.end());
//             res.push_back(*max_tmp);
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size() == 0) return {};
        deque<int> win;
        vector<int> res;
        for(int i=0; i<k; i++) win.push_back(nums[i]);
        int max;
        auto max_tmp = max_element(win.begin(), win.end());
        max = *max_tmp;
        res.push_back(max);
        for(int i =1; i<nums.size()-k+1; i++){
            // win.pop_front();
            // win.push_back(nums[i+k-1]);
            // max_tmp = max_element(win.begin(), win.end());
            // res.push_back(*max_tmp);
            if(win.front() == max){
                win.pop_front();
                win.push_back(nums[i+k-1]);
                max_tmp = max_element(win.begin(), win.end());
                max = *max_tmp;
                res.push_back(max);
            }
            else{
                if(nums[i+k-1] > max) {
                    max = nums[i+k-1];
                    res.push_back(max);
                }  
                else {
                    
                    res.push_back(max);
                }
                win.pop_front();
                win.push_back(nums[i+k-1]);
            }                        
        }
        return res;
    }
};

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         //判断特殊情况
//         int n = nums.size();
//         if(n < k || k <= 0) return {};
//         //滑动窗口的前后指针
//         int low =  1 - k,high = 0; 
        
//         deque<int> dq;//双端队列
//         vector<int> res;
        
//         while(high < n){
//             //判断滑窗的low端是否是最大的元素
//             if(low >= 1 && nums[low - 1] == dq[0]) dq.pop_front();
 
//             while(!dq.empty() && dq[0] < nums[high]) dq.pop_front();//小于nums[high]的元素出队
//             while(!dq.empty() && dq[dq.size()-1] < nums[high]) dq.pop_back();//小于nums[high]的元素出队

//             //此时的high指针进队
//             dq.push_back(nums[high]);

//             if(low >= 0) res.push_back(dq[0]);//当low >= 0，滑窗已经形成
//             low ++;
//             high ++;
//         }
//         return res;
//     }
// };