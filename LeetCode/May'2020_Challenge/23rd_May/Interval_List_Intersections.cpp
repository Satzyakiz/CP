// Given two lists of closed intervals, each list of intervals
// is pairwise disjoint and in sorted order.
//
// Return the intersection of these two interval lists.
//
// (Formally, a closed interval [a, b] (with a <= b) denotes
// the set of real numbers x with a <= x <= b.  The intersection
// of two closed intervals is a set of real numbers that is either
// empty, or can be represented as a closed interval.  For example,
// the intersection of [1, 3] and [2, 4] is [2, 3].)

vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
	vector<vector<int>> intersections;
	int i=0, j=0;
	while( i < A.size() && j < B.size() ) {
		// check if the interval A[i] intersects with B[j]
		// check if one of the interval's start time lies within the other interval
		if( ( A[i][0] >= B[j][0] && A[i][0] <= B[j][1] ) ||
			( B[j][0] >= A[i][0] && B[j][0] <= A[i][1] ) ) {
			// store the intersection part
			intersections.push_back( { max( A[i][0], B[j][0] ), min( A[i][1], B[j][1] ) } );
		}
		// move next from the interval which is finishing first
		if( A[i][1] < B[j][1] )
			i++;
		else
			j++;
	}
	return intersections;
}
