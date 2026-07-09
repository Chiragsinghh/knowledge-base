class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = INT_MIN;
        int i=0;
        int j=height.size()-1;

        while(i<j){
            int h = min(height[i],height[j]);
            int l = j-i;
            int w = h*l;
            ans = max(ans,w);

            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
        }
        return ans;
    }
};