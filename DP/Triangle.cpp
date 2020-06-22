
// Given a triangle, find the minimum path sum from top to bottom. 
// Each step you may move to adjacent numbers on the row below.
//
// For example, given the following triangle
//
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

// As in each step we can move only to the adjacent indexes,
// we choose the minimum value.
// minArr stores the the last row of triangle in the beginning,
// and on corresponding loops, it stores the min distance from that
// row to the bottom row of triangle vector.

int minimumTotal(vector<vector<int>>& triangle) {
	int n = triangle.size();
	vector<int> minArr(triangle.back());
	for(int length = n-2; length >=0; length--){
		for(int i=0; i<=length; i++){
			minArr[i] = min(minArr[i],minArr[i+1]) + triangle[length][i];
		}
	}
	return minArr[0];
}
