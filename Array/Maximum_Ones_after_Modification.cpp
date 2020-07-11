// Given a binary array A and a number B, we need to find
// length of the longest subsegment of ‘1’s possible by changing
// at most B ‘0’s.

// Input 1:
//
//  A = [1, 0, 0, 1, 1, 0, 1]
//  B = 1
// Input 2:
//
//  A = [1, 0, 0, 1, 0, 1, 0, 1, 0, 1]
//  B = 2
//
//
// Example Output
// Output 1:
//
//  4
// Output 2:
//
//  5

int Solution::solve(vector<int> &A, int B) {
    int left = 0, count = 0,ans = INT_MIN;
    for(int i=0; i<A.size(); i++){
        if(A[i] == 0){
            count++;
        }
        while(count > B){
            if(A[left] == 0){
                count--;
            }
            left++;
        }
        ans = max(ans, i-left+1);
    }
    return ans;
}
