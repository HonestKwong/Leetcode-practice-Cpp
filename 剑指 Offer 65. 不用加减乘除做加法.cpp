class Solution {
public:
    int add(int a, int b) {
        unsigned int c =0;
        while(b!=0){
            c = (a&b);
            a ^= b;
            b = c<<1;
        }
        return a;
    }
};