class Solution {
public:
    bool solve(vector<int>& bloomDay, int m, int k,int mid){
        int h=k;
        for(auto day:bloomDay){
            if(day>mid){
                h=k;
            }else{
                h--;
                if(h==0){
                m--;
                h=k;
                if(m==0){
                    return true;
                }
                }
            }
            
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans = INT_MAX;
        int start =0;
        int end = *max_element(bloomDay.begin(),bloomDay.end());

        while(start<=end){
            int mid = (start+end)/2;
            if(solve(bloomDay,m,k,mid)){
                end = mid-1;
                ans = min(mid,ans);
            }
            else{
                start = mid+1;
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};