class Solution {
public:
    bool isMatch(string s, string p) {
        const int n = s.size();
        const int m = p.size();
        vector<vector<bool>> f(n + 1, vector<bool>(m + 1, false));

        for(int i=0; i<=n; i++){
            for(int j=0; j<=m;j++){
                if(j == 0){
                    f[i][j] = i==0;
                }else{
                    if(p[j-1]!='*'){
                        if(i>0 && (s[i-1]==p[j-1] || p[j-1]=='.')){
                            f[i][j]=f[i-1][j-1];
                        }
                    }else{
                        if(j>=2){
                            f[i][j] = f[i][j]||f[i][j-2];
                        }
                        if(i>=1&&j>=2&&(s[i-1]==p[j-2]||p[j-2]=='.')){
                            f[i][j] = f[i][j]||f[i-1][j];
                        }
                    }
                }
            }
        }
        return (bool)f[n][m];
    }
};

class Solution2 {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        int f[n + 1][m + 1];

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                //分成空正则和非空正则两种
                if (j == 0) {
                    f[i][j] = i == 0;
                } else {
                    //非空正则分为两种情况 * 和 非*
                    if (p[j-1] != '*') {
                        if (i > 0 && (s[i-1] == p[j-1] || p[j-1] == '.')) {
                            f[i][j] = f[i - 1][j - 1];
                        }
                    } else {
                        //碰到 * 了，分为看和不看两种情况
                        //不看
                        if (j >= 2) {
                            f[i][j] = f[i][j] || f[i][j - 2];
                        }
                        //看
                        if (i >= 1 && j >= 2 && (s[i-1] == p[j - 2] || p[j-2] == '.')) {
                            f[i][j] = f[i][j]||f[i - 1][j];
                        }
                    }
                }
            }
        }
        return (bool)f[n][m];
    }
};

class Solution3 {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        if(p[1] == '*'){
            return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.')) && isMatch(s.substr(1), p);
        }
        else{
            return !s.empty() && (s[0] == p[0] || p[0] == '.') && (isMatch(s.substr(1), p.substr(1)));
        }
    }
};
