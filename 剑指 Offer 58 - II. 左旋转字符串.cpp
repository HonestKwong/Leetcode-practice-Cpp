class Solution {
public:
    string reverseLeftWords(string s, int n) {
        // reverse(s.begin(), s.begin()+n);
        // reverse(s.begin()+n, s.end());
        // reverse(s.begin(), s.end());
        // return s;

        string re = "";
        for(int i = n; i < s.length(); i++) re += s[i];
        for(int i = 0; i < n; i++) re += s[i];
        return re;
    }
};