
// Given an integer array A of size N. You need to count the number of
// special elements in the given array.
//
// A element is special if removal of that element make the array balanced.
//
// Array will be balanced if sum of even index element equal to sum of odd
// index element.
//
// Input 1:
//
//  A = [2, 1, 6, 4]
// Input 2:
//
//  A = [5, 5, 2, 5, 8]
//
//
// Example Output
// Output 1:
//
//  1
// Output 2:
//
//  2
//
//
// Example Explanation
// Explanation 1:
//
//  After deleting 1 from array : {2,6,4}
//     (2+4) = (6)
//  Hence 1 is the only special element, so count is 1
// Explanation 2:
//
//  If we delete A[0] or A[1] , array will be balanced
//     (5+5) = (2+8)
//  So A[0] and A[1] are special elements, so count is 2.


int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<int> oddSum, evenSum;
    oddSum.emplace_back(0);
    evenSum.emplace_back(0);

    for(int i=0; i<A.size(); i++){
//as oddSum and evenSum already has an element, its odd and even index is
//reciprocal of the current index
        if(!(i & 1)){
            oddSum.emplace_back(oddSum.back() + A[i]);
            evenSum.emplace_back(evenSum.back());
        }else{
            evenSum.emplace_back(evenSum.back() + A[i]);
            oddSum.emplace_back(oddSum.back());
        }
    }
    int ans = 0;
    for(int i=1; i<=A.size(); i++){
        int even = 0, odd = 0;
        if(i & 1){
            even = evenSum[i] + oddSum[A.size()] - oddSum[i] ;
            odd = oddSum[i-1] + evenSum[A.size()] - evenSum[i];
        }else{
            even = evenSum[i-1] + oddSum[A.size()] - oddSum[i];
            odd = oddSum[i] + evenSum[A.size()] - evenSum[i];
        }
        if(even == odd)
            ans++;
    }

    return ans;
}
