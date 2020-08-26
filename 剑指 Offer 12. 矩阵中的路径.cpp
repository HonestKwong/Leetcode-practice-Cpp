class Solution {
//这个答案效率很低，深度优先方法
public:
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k){
        if(i>=board.size() || i<0 || j>=board[0].size() || j<0 || board[i][j] != word[k]) 
            return false;
        if(k==word.size()-1) return true;
        char temp = board[i][j];
        board[i][j] = '/';
        bool res = dfs(board, word, i+1, j, k+1) || dfs(board, word, i-1, j, k+1) || 
                   dfs(board, word, i, j+1, k+1) || dfs(board, word, i, j-1, k+1);
        board[i][j]=temp;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};