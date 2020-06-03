
// Input: [2, 6, 4, 8, 10, 9, 15]
// Output: 5
// Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make
// the whole array sorted in ascending order.


int findUnsortedSubarray(vector<int>& A) {
        int start = -1,end = -1;
        int i=0, n = A.size();
        while(i<n-1 && A[i] <= A[i+1])
            i++;
        if(i == n-1) return 0;
        start = i;
        int tempMax = A[start],tempMin = A[start];
        while(i<n){
            if(A[i] < tempMax){
                end = i;
            }
            if(A[i] > tempMax){
                tempMax = A[i];
            }else if(tempMin > A[i]){
                tempMin = A[i];
            }

            i++;
        }
        if(tempMin < A[start]){
            i = start;
            while(i>=0 && A[i] > tempMin)
                i--;
            start = i+1;
        }
        return end-start+1;
    }
