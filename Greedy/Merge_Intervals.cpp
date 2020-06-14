

// Given a collection of intervals, merge all overlapping intervals.
//
// Example 1:
//
// Input: [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
// Example 2:
//
// Input: [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.


    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        if(intervals.size() == 0 || intervals.size() == 1) return intervals;
        for(int i=0; i<intervals.size(); i++){
            int j=i+1;
            int first = intervals[i][0];
            int second = intervals[i][1];
            while(j<intervals.size() && intervals[j][0] <= second){
                first = min(first,intervals[j][0]);
                second = max(second,intervals[j][1]);
                j++;
            }
            i=j-1;
            ans.push_back({first,second});
        }
        return ans;
    }
