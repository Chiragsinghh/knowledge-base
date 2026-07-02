class Solution {
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[0]<b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end(),cmp);

        

        int i=0;
        while(i<intervals.size()){
            int start = intervals[i][0];
            int end = intervals[i][1];
            while(i + 1 < intervals.size() && intervals[i+1][0] <= end){
                end = max(end, intervals[i + 1][1]);
                i++;
            }

            ans.push_back({start,end});
            i++;

        }
        return ans;

    }
};