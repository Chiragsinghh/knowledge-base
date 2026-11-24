class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        dist[0][0] = grid[0][0];

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > q;

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        q.push({grid[0][0],{0,0}});

        while(!q.empty()){
            auto [time,coor] = q.top();
            int x = coor.first;
            int y = coor.second;
            q.pop();

            if (time > dist[x][y])
                continue;

            if (x == n-1 && y == n-1)
                return time;

            for(int i=0;i<4;i++){
                int newx = x+dx[i];
                int newy = y+dy[i];

                if(newx>=0 && newx<n && newy>=0 && newy<n){

                    int newtime = max(time,grid[newx][newy]);

                    if(newtime < dist[newx][newy]){
                        dist[newx][newy] = newtime;
                        q.push({newtime,{newx,newy}});
                    }
                }
            }
        }

        return -1;

    }
};