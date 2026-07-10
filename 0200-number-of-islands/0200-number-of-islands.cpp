class Solution {
public:
    bool isSafe(int x,int y,int& m,int &n,vector<vector<char>>& grid){
        if(x>=0 && x<=m-1 && y>=0 && y<=n-1 && grid[x][y]=='1'){
            return true;
        }else{
            return false;
        }
    }
    void solve(int x,int y,int &m,int &n,vector<vector<char>>& grid,vector<vector<bool>>&vis){
        vis[x][y]=true;

        int dx[] = {+1,-1,0,0};
        int dy[] = {0,0,+1,-1};

        for(int i=0;i<4;i++){
            int newx = x+dx[i];
            int newy = y+dy[i];
            if(isSafe(newx,newy,m,n,grid)){
                if(!vis[newx][newy]){
                    solve(newx,newy,m,n,grid,vis);
                }
                
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>>vis(m,vector<bool>(n,false));

        int ans =0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    solve(i,j,m,n,grid,vis);
                    ans++;
                }
            }
        }

        return ans;


    }
};