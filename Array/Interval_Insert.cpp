// Given a set of non-overlapping intervals, insert a new interval into 
// the intervals (merge if necessary).
//
// You may assume that the intervals were initially sorted according to
// their start times.
//
// Example 1:
//
// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]
// Example 2:
//
// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ans;
    for(auto i: intervals){
        if(newInterval.size()){
            if(i[1] < newInterval[0]){
                ans.push_back(i);
            }else if(newInterval[1] < i[0]){
                ans.push_back(newInterval);
                ans.push_back(i);
                newInterval.clear();
            }
            else{
                newInterval[0] = min(i[0], newInterval[0]);
                newInterval[1] = max(i[1], newInterval[1]);
            }
        }else{
            ans.push_back(i);
        }
    }
    if(newInterval.size())
        ans.push_back(newInterval);
    return ans;
}
