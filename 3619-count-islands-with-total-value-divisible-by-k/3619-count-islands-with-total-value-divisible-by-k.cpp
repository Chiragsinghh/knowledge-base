class Solution {
public:
    void countsum(int i,int j,int& m,int& n,vector<vector<int>>& copy,long long& sum){
        if(i<0 || i>=m || j<0 || j>=n || copy[i][j]==0){
            return;
        }

        sum+=copy[i][j];
        copy[i][j]=0;
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        for(int p=0;p<4;p++){
            countsum(i+dx[p],j+dy[p],m,n,copy,sum);
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        vector<vector<int>> copy = grid;

        int m = grid.size();
        int n = grid[0].size();
        int ans =0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(copy[i][j]>0){
                    long long sum =0;
                    countsum(i,j,m,n,copy,sum);
                    if(sum%k==0){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};