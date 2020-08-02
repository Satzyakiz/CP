// There are a row of N houses, each house can be painted with one of the
// three colors: red, blue or green.
//
// The cost of painting each house with a certain color is different.
// You have to paint all the houses such that no two adjacent houses
// have the same color.
//
// The cost of painting each house with a certain color is represented
// by a N x 3 cost matrix A.
//
// For example, A[0][0] is the cost of painting house 0 with color red;
// A[1][2] is the cost of painting house 1 with color green, and so on.
//
// Find the minimum total cost to paint all houses.

// Input 1:
//
//  A = [  [1, 2, 3]
//         [10, 11, 12]
//      ]
//
//
// Example Output
// Output 1:
//
//  12

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    if(n == 0)
        return 0;

    int red,blue,green;
    red = A[0][0], blue = A[0][1], green = A[0][2];
    for(int i=1; i < n; i++){
        int nRed = min(green,blue) + A[i][0];
        int nBlue = min(green,red) + A[i][1];
        int nGreen = min(red,blue) + A[i][2];

        red = nRed, blue = nBlue, green = nGreen;
    }

    return min(red,min(green,blue));
}
