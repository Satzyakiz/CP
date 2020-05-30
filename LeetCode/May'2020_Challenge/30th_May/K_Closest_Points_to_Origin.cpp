// Input: points = [[1,3],[-2,2]], K = 1
// Output: [[-2,2]]
// Explanation:
// The distance between (1, 3) and the origin is sqrt(10).
// The distance between (-2, 2) and the origin is sqrt(8).
// Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
// We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
// Example 2:
//
// Input: points = [[3,3],[5,-1],[-2,4]], K = 2
// Output: [[3,3],[-2,4]]
// (The answer [[-2,4],[3,3]] would also be accepted.)

//Using max-heap implementation

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<tuple<double,int,int>> h;
        for(int i=0; i<points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];
            double d = distance(x,y);
            h.push({d,x,y});
            if(h.size() > K)
                h.pop();
        }
        vector<vector<int>> ans(K,vector<int>(2));
        int i=0;
        while(!h.empty()){
            int a = get<1>(h.top());
            int b = get<2>(h.top());
            // cout<<a<<" "<<b<<endl;
            ans[i][0] = a;
            ans[i++][1] = b;
            h.pop();
        }
        return ans;
    }
