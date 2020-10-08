class MedianFinder {
public:
//据说会超时
    vector<double> res;
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        res.push_back(num);
    }
    
    double findMedian() {
        sort(res.begin(),res.end());
        if(res.size() % 2) return res[res.size()/2 ];
        return (res[res.size()/2 - 1] + res[res.size()/2])/2;
    }
};


class MedianFinder {
//插入时就进行排序
public:
    vector<double> res;
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(res.empty()) res.push_back(num);
        else res.insert(lower_bound(res.begin(),res.end(),num),num); //插入时就进行排序
    }
    
    double findMedian() {
        // sort(res.begin(),res.end());
        if(res.size() % 2) return res[res.size()/2 ];
        return (res[res.size()/2 - 1] + res[res.size()/2])/2;
    }
};


class MedianFinder {
public:
    priority_queue<int> lo;                              // 大顶堆
    priority_queue<int, vector<int>, greater<int>> hi;   // 小顶堆

    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        lo.push(num);
        hi.push(lo.top());
        lo.pop();
        if(lo.size()<hi.size()){
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
        // sort(res.begin(),res.end());
        
        return(lo.size()>hi.size())? ( double(lo.top())) : ( (lo.top()+hi.top())*0.5);
    }
};