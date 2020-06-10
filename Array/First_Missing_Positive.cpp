// Given an unsorted integer array, find the smallest missing
// positive integer.
//
// Example 1:
//
// Input: [1,2,0]
// Output: 3
// Example 2:
//
// Input: [3,4,-1,1]
// Output: 2
// Example 3:
//
// Input: [7,8,9,11,12]
// Output: 1

int firstMissingPositive(vector<int>& A) {
        int n=A.size();
        for(int i=0; i<n; i++){
            while(A[i] > 0 && A[i] <= n && A[A[i]-1] != A[i])
                swap(A[i],A[A[i]-1]);
        }
        for(int i=0; i<n; i++){
            if(A[i] != i+1)
                return i+1;
        }
        return n+1;
    }
// We visit each number once, and each number will be put in its 
// right place at most once, so it is O(n) + O(n). Although there
// are two nesting of cyclic (for and while), but its time complexity
// is still O(n).
