class Solution1 {
public:
    int minArray(vector<int>& numbers) {
        if(numbers.size()==0) return 0;
        for(int i=0; i<numbers.size()-1; i++){
            if(numbers[i]>numbers[i+1]) return numbers[i+1];
        }
        return numbers[0];
    }
};
class Solution2 {
public:
    int minArray(vector<int>& numbers) {
        if(numbers.size()==0) return 0;
        auto p = numbers.begin();
        auto q = numbers.end();
        for(; p!=q-1; p++){  //不等于的方法只有8ms，小于的方法有16~20ms,不知道为何？
            if(*p>*(p+1)) return *(p+1);
        }
        return numbers[0];
    }
};


class Solution {
public:
    //二分还不如暴力法，不知为何
    int minArray(vector<int>& numbers) {
        int low = 0;
        int high = numbers.size() - 1;
        while (low < high) {
            int pivot = low + (high - low) / 2;
            if (numbers[pivot] < numbers[high]) {
                high = pivot;
            }
            else if (numbers[pivot] > numbers[high]) {
                low = pivot + 1;
            }
            else {
                high -= 1;
            }
        }
        return numbers[low];
    }
};