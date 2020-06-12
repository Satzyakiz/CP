// There are a number of spherical balloons spread in two-dimensional space. 
// For each balloon, provided input is the start and end coordinates of the
// horizontal diameter. Since it's horizontal, y-coordinates don't matter and
// hence the x-coordinates of start and end of the diameter suffice.
// Start is always smaller than end.
// Input:
// [[10,16], [2,8], [1,6], [7,12]]
//
// Output:
// 2
//
// Explanation:
// One way is to shoot one arrow for example at x = 6
// (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11
// (bursting the other two balloons).

static bool Compare(const vector<int> a,const vector<int> b){
        if(a[1] == b[1])
            return a[0] < b[0];
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),Compare);
        int ans = 0,lastArrow = -1;
        for(int i=0; i<points.size(); i++){
            if(lastArrow != -1 && points[i][0] <= lastArrow)
                continue;
            lastArrow = points[i][1];
            ans++;
        }
        return ans;
    }
