// For example,
//
// A = [1, 1, 1, 2, 2]
//
// Return: 4

int Solution::nTriang(vector<int> &A) {
    int ans = 0, n = A.size(), num = pow(10, 9) + 7;
    if(n == 0){
        return ans;
    }
    sort(A.begin(), A.end());
    for(int k = n - 1; k >= 0; k--){
        int i = 0, j = k - 1;
        while(i < j){
            long int miniSum = A[i] + A[j], maxi = A[k];
            if(A[i] + A[j] > A[k]){
                ans = (ans + (j - i)%num)%num;
                j--;
            }
            else{
                i++;
            }
        }
    }

    return ans;
}
//
// Approach: First sort the array, and run a nested loop, fix an index and
// then try to fix an upper and lower index within which we can use all the
// lengths to form a triangle with that fixed index.
//
// Algorithm:
// Sort the array and then take three variables l, r and i, pointing to start,
// end-1 and array element starting from end of the array.
//
// Traverse the array from end (n-1 to 1), and for each iteration keep the
// value of l = 0 and r = i-1
//
// Now if a triangle can be formed using arr[l] and arr[r] then triangles
// can obviously formed from a[l+1], a[l+2]…..a[r-1], arr[r] and a[i],
// because the array is sorted , which can be directly calculated using (r-l).
// and then decrement the value of r and continue the loop till l is less than r
//
// If triangle cannot be formed using arr[l] and arr[r] then increment the value
// of r and continue the loop till l is less than r
//
// So the overall complexity of iterating
// through all array elements reduces.
