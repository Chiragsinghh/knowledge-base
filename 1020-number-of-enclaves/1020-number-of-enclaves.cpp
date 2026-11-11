class Solution {
public:
    void solve(int x,int y,int n,int m,vector<vector<int>>& grid){
        if(x<0 || x>=n || y<0 || y>=m || grid[x][y]==0){
            return;
        }

        grid[x][y]=0;
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        for(int i=0;i<4;i++){
            solve(x+dx[i],y+dy[i],n,m,grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int ans =0;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<m;i++){
            if(grid[0][i]==1){
                solve(0,i,n,m,grid);
            }
        }

        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                solve(i,0,n,m,grid);
            }
        }

        for(int i=0;i<m;i++){
            if(grid[n-1][i]==1){
                solve(n-1,i,n,m,grid);
            }
        }

        for(int i=0;i<n;i++){
            if(grid[i][m-1]==1){
                solve(i,m-1,n,m,grid);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans++;
                }
            }
        }

        return ans;
    }
};