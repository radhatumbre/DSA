class Solution {
public:
    void bfs(int i,int j, int n, int m,vector<vector<char>>& grid, vector< vector<int> > &vis){
        vis[i][j] = 1;
        queue< pair<int,int> > q;
        q.push({i,j});
        while(!q.empty()){
            auto [a, b] = q.front();
            q.pop();
            // up
            if(a>0 && grid[a-1][b]=='1' && !vis[a-1][b]){
                vis[a-1][b] = 1;
                q.push({a-1,b});
            }
            // down
            if(a<n-1 && grid[a+1][b]=='1' && !vis[a+1][b]){
                vis[a+1][b] = 1;
                q.push({a+1,b});
            }
            // left
            if(b>0 && grid[a][b-1]=='1' && !vis[a][b-1]){
                vis[a][b-1] = 1;
                q.push({a,b-1});
            }
            // right
            if(b<m-1 && grid[a][b+1]=='1' && !vis[a][b+1]){
                vis[a][b+1] = 1;
                q.push({a,b+1});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int result = 0;

        vector< vector<int> > vis(n, vector<int> (m, 0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    result++;
                    bfs(i,j,n,m,grid,vis);
                }
            }
        }
        return result;
    }
};