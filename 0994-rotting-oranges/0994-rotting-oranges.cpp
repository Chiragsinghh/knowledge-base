class Solution {
public:
    bool isSafe(int x,int y,int n,int m,vector<vector<int>>& grid){
        if(x<0 || y<0 || x>=n || y>=m){
            return false;
        }
        if(grid[x][y]==1) return true;
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m =grid[0].size();
        queue<pair<int,int>>q;

        int freshcount =0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    freshcount++;
                }
            }
        }

        int ans =0;

        while(!q.empty() && freshcount>0){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto curr = q.front();
                q.pop();
                int x = curr.first;
                int y = curr.second;

                int dx[] = {1,-1,0,0};
                int dy[] = {0,0,1,-1};
                for(int i=0;i<4;i++){
                    if(isSafe(x+dx[i],y+dy[i],n,m,grid)){
                        grid[x+dx[i]][y+dy[i]] = 2;
                        freshcount--;
                        q.push({x+dx[i],y+dy[i]});
                    }
                }
                
            }
            ans++;
        }

        if(freshcount>0) return -1;
        return ans;
    }
};