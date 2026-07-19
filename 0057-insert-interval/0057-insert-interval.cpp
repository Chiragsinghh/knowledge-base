class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int start = newInterval[0];
        int end = newInterval[1];
        int n = intervals.size();
        vector<vector<int>>ans;

        int i=0;
        while(i<n && intervals[i][1]<start){
            ans.push_back(intervals[i]);
            i++;
        }
         while(i<n && intervals[i][0]<=end){
            end = max(end,intervals[i][1]);
            start = min(start,intervals[i][0]);
            i++;
        }
        ans.push_back({start,end});

        while(i<intervals.size()){
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};