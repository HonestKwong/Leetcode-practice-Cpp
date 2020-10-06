class Solution {
public:
    vector<string> permutation(string s) {
        if(s.empty()) return {};
        vector<string> res;
        sort(s.begin(),s.end());
        vector<bool> visit(s.size(),false);
        string track;

        trackback(res, s, visit, track);
        return res;
    }

    void trackback(vector<string>& res, string s, vector<bool>& visit, string& track){
        //排除不合法的思路
        if(track.size() == s.size()){
            res.push_back(track);
            return;
        }

        for(int i=0; i<s.size(); i++){
            if(visit[i]) continue;
            if(i>0 && !visit[i-1] && s[i-1]==s[i]) continue; //
            visit[i] = true;

            track.push_back(s[i]);
            trackback(res, s, visit, track);
            track.pop_back();
            visit[i] = false;
        }
    }
};