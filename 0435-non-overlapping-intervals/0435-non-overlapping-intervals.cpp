class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] != b[0]) {
            return a[0] < b[0]; // Fixes strict weak ordering violation
        }
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();

        int ans =0;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0] < end){
                ans++;
                end = min(end, intervals[i][1]);
            }else{
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        return ans;
    }
};