class Solution {
public:
    void solve(int x,int y,int m,int n,int old,int color,vector<vector<int>>& image){
        if(x>=m || y>=n || x<0 || y<0 || old == color || image[x][y]!= old){
            return ;
        }

        image[x][y]=color;

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        for(int i=0;i<4;i++){
            solve(x+dx[i],y+dy[i],m,n,old,color,image);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldcolor = image[sr][sc]; 
        int m = image.size();
        int n = image[0].size();
        solve(sr,sc,m,n,oldcolor,color,image);
        return image;
    }
};