class Solution {
public:
    bool solve(vector<int>& weights, int capacity, int days) {

    int requiredDays = 1;
    int currentLoad = 0;

    for (int w : weights) {

        if (currentLoad + w <= capacity) {
            currentLoad += w;
        } else {
            requiredDays++;
            currentLoad = w;
        }
    }

    return requiredDays <= days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;

        for(int w:weights){
            sum+=w;
        }

        int start = *max_element(weights.begin(), weights.end());
        int end = sum;
        int ans;

        while(start<=end){
            int mid = (start+end)/2;
            if(solve(weights,mid,days)){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }

        return ans;

    }
};