class Solution {
public:
    void dfs(int &curr,int i,int j,vector<vector<int>> &vis,vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        if(i-1>=0 && grid[i-1][j]==1 && vis[i-1][j]==0){
            curr+=1;
            vis[i-1][j] = curr;
            dfs(curr,i-1,j,vis,grid);
        }
        if(i+1<n && grid[i+1][j]==1&& vis[i+1][j]==0){
            curr+=1;
            vis[i+1][j] = curr;
            dfs(curr,i+1,j,vis,grid);
        }
        if(j-1>=0 && grid[i][j-1]==1 && vis[i][j-1]==0){
            curr+=1;
            vis[i][j-1] = curr;
            dfs(curr,i,j-1,vis,grid);
        }
        if(j+1<m && grid[i][j+1]==1 && vis[i][j+1]==0){
            curr+=1;
            vis[i][j+1] = curr;
            dfs(curr,i,j+1,vis,grid);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        int curr = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    vis[i][j] = 1;
                    dfs(curr,i,j,vis,grid);
                    curr = 1;
                }
            }
        }
        int mx = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mx = max(mx,vis[i][j]);
            }
        }
        return mx;
    }
};