class Solution {
public:
    int solve(int& mid,long long h,vector<int>& piles){
        long long total =0;

        for(auto pile:piles){
            total += (pile+mid-1 )/mid;
        }
        if(total>h){
            return false;
        }
        return total<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = *max_element(piles.begin(), piles.end());
        
        int ans = INT_MAX;
        int start = 1;
        int end = maxi;

        while(start<=end){
            int mid = (start+end)/2;
            if(solve(mid,h,piles)){
                ans = min(mid,ans);
                end=mid-1;
            }else{
                start=mid+1;
            }  
            
        }

        return ans;
    }
};