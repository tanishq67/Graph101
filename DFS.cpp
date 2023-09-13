https://leetcode.com/problems/number-of-islands/description/
===========================================================
class Solution {
public:
    int n, m;
    vector<vector<int>> vis;
    vector<vector<char>> g;
    struct node{
        int x,y;
    };
    bool isInside(node c){
        // cout<<c.x<<" "<<c.y<<"\n";
        return c.x < n && c.x >=0 && c.y < m && c.y >=0;
    }
    void dfs(node c){
        vis[c.x][c.y] = 1;
        int dx[] = {0,0,-1,1};
        int dy[] = {1,-1,0,0};
        
        for(int d = 0; d < 4; d++){
            int nx = dx[d] + c.x, ny = dy[d] + c.y;
            if(isInside({nx,ny}) && g[nx][ny] == '1' && !vis[nx][ny]){
                // vis[nx][ny] = 1;
                dfs({nx,ny});
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        g = grid;
        vis = vector<vector<int>>(n,vector<int>(m,0));
        int cnt = 0;
        for(int i = 0; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(g[i][j] == '1' && !vis[i][j]){
                    cnt++, dfs({i,j});
                }
            }
        }
        return cnt;
    }
};
