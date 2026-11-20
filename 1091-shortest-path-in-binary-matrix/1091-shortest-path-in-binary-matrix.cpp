class Solution {
public:
    bool isSafe(int x,int y,int n,vector<vector<int>>& grid,vector<vector<bool>>&vis){
        if(x>=0 && x<n && y>=0 && y<n && !vis[x][y] && grid[x][y]==0){
            return true;
        }
        return false;
        
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        int n = grid.size();

        queue<pair<pair<int,int>,int>>q;
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        if(grid[0][0]!=0) return -1;

        q.push({{0,0},1});
        vis[0][0] = true;

        int dx[] = {1,-1,1,1,-1,-1,0,0};
        int dy[] = {0,0,-1,1,-1,1,1,-1};

        while(!q.empty()){
            auto [coor,dist] = q.front();
            int x = coor.first;
            int y = coor.second;


            q.pop();

            if(x==n-1 && y== n-1){
                return dist;
            }


            for(int i=0;i<8;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(isSafe(nx,ny,n,grid,vis)){
                    vis[nx][ny]=true;
                    q.push({{nx,ny},dist+1});
                }
            }
        }

        return -1;
    }
};