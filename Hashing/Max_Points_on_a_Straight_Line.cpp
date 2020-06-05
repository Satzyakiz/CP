//Leetcode (Hard)
// Example 1:
//
// Input: [[1,1],[2,2],[3,3]]
// Output: 3
// Explanation:
// ^
// |
// |        o
// |     o
// |  o
// +------------->
// 0  1  2  3  4
// Example 2:
//
// Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
// Output: 4
// Explanation:
// ^
// |
// |  o
// |     o        o
// |        o
// |  o        o
// +------------------->
// 0  1  2  3  4  5  6
// Approach:
// i) If the no of points is less than or equal to 2,
// then that particular no is the answer.
// ii) For each point, we find out
// a) how many duplicates it have
// b) how many points lie on the same x-axis as that point
// c) which slope of that point has the maximum no of points in it
// For these reasons, every point has its own map and other variables.
// iii) After checking all other points from i+1 to n-1 for i-th point,
// the answer is compared
// with previous maximum ans and if the new localAns is maximum,
// it is stored in the ans.


int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2)
            return n;
        int ans = 0;
        for(int i=0; i< n; i++){
            int local = 1;          //To hold the local result
            int vertical = 1;      // To check if both points are on the same line on x axis
            int duplicate = 0;     //To keep count of duplicates
            unordered_map<long double,int> um;
            for(int j=i+1;j<n; j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                if(x2 == x1 && y2 == y1)
                    duplicate++;
                else if(x2 - x1 == 0)
                    vertical++;
                else{
                    long double numerator = (y2-y1);
                    long double denominator = (x2-x1);
                    long double slope = numerator/denominator; //Formula to find out slope
                    if(um[slope] == 0)
                        um[slope] = 2;
                    else
                        um[slope]++;

                    local = max(local,um[slope]);     // Check if the current slope has max no of points
                                                     //or the previous slope had the most no of points
                }
            }
            local = max(local+duplicate,vertical+duplicate);  //Adding the duplicates while checking as those will fetch similar results
            ans = max(ans,local);
        }
        return ans;

    }
