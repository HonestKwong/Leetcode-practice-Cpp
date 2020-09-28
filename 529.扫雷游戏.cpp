/*
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 */

// @lc code=start
class Solution {
public:
    int dir_x[8] = {0, 1, 0, -1, 1, -1, 1, -1};
    int dir_y[8] = {1, 0, -1, 0, 1, 1, -1, -1};

    void dfs(vector<vector<char>>& board, int x, int y){
        int count = 0;
        for(int i =0; i<8; i++){
            int tmp_x = x + dir_x[i];
            int tmp_y = y + dir_y[i];
            if(tmp_x<0 || tmp_x>=board.size() || tmp_y<0 || tmp_y>=board[0].size()) continue;
            count += board[tmp_x][tmp_y] == 'M';

        }
        if(count > 0) board[x][y] = '0' + count;
        else{
            board[x][y] = 'B';
            for(int i = 0; i<8; i++){
                int tmp_x = x + dir_x[i];
                int tmp_y = y + dir_y[i];
                if(tmp_x<0 || tmp_x>=board.size() || tmp_y<0 || tmp_y>=board[0].size()|| board[tmp_x][tmp_y]!='E') continue;
                dfs(board,tmp_x,tmp_y);
            }
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return board;
            }
        else dfs(board,click[0],click[1]);
        return board;
    }
};
// @lc code=end

