class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] != b[0]) {
            return a[0] < b[0];
        }
        return a[1] < b[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>> ans;
        int start = intervals[0][0];
        int end = intervals[0][1];
        int n= intervals.size();

        int i=1;
        while(i<n){
            if(intervals[i][0]<=end){
                end = max(intervals[i][1],end);
            }else{
                ans.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            i++;
        }
        ans.push_back({start,end});

        return ans;
    }
};