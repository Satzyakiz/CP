
// Given an 2D integer array A of size N x 2 denoting time intervals
// of different meetings.
//
// Where:
//
// A[i][0] = start time of the ith meeting.
// A[i][1] = end time of the ith meeting.
// Find the minimum number of conference rooms required so that
// all meetings can be done.

// Input 1:
//
//  A = [      [0, 30]
//             [5, 10]
//             [15, 20]
//      ]
//
// Input 2:
//
//  A =  [     [1, 18]
//             [18, 23]
//             [15, 29]
//             [4, 15]
//             [2, 11]
//             [5, 13]
//       ]
//
//
// Example Output
// Output 1:
//
//  2
// Output 2:
//
//  4
//
int Solution::solve(vector<vector<int> > &A) {
    map<int,int> um;
    for(vector<int> &v: A){
        um[v[0]]++;
        um[v[1]]--;
    }
    int c = 0, total = 0;
    for(auto itr = um.begin(); itr != um.end(); itr++){
        c += itr->second;
        total = max(total, c);
    }
    return total;
}

//Map is req as order is important here
