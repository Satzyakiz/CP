//Same as bitonic array
// Example 1:
//
// Input: [0,1,0]
// Output: 1
// Example 2:
//
// Input: [0,2,1,0]
// Output: 1

int peakIndexInMountainArray(vector<int>& A) {
    if(A.size() == 1)
        return A[0];
    int n = A.size();
    if(A[0] > A[1])
        return A[0];
    if(A[n-1] > A[n-2])
        return A[n-1];
    int l = 0, h = n-1;
    while(l <= h){
        int mid = l + (h-l)/2;
        int prev = (mid-1+n)%n;
        int next = (mid+1)%n;
        if(A[mid] > A[next] && A[mid] > A[prev]){
            return mid;
        }
        if(A[mid] < A[next]){
            l = mid+1;
        }else{
            h = mid-1;
        }
    }

    return -1;
}
