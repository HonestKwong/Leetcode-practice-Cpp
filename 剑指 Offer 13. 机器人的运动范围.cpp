class Solution {
    //这个方法使用的是BFS，广度优先算法，还有深度优先算法，没有特别理解，还可以参考，JZ offer12 DFS问题
private:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int sumdigit(int i, int j){
        int res = 0;    // 不初始化会导致运行结果错误，必须初始化为0
        while(i>0){
            res += i%10;
            i = i/10;
        }
        while(j>0){
            res += j%10;
            j = j/10;
        }
        return res;
    }
    int movingCount(int m, int n, int k) {
        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        q.push({0,0});
        int result = 0;
        visited[0][0] = 1;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int x = front.first;
            int y = front.second;
            result++;
            for(auto d: directions){
                int new_x = x + d.first;
                int new_y = y + d.second;
                if(new_x<0||new_x>=m||new_y<0||new_y>=n
                || visited[new_x][new_y] == 1 || 
                sumdigit(new_x,new_y)>k)
                    continue;
                q.push({new_x,new_y});
                visited[new_x][new_y]=1;
            }
        }
        return result;
    }
};