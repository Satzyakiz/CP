// You are given an array A containing N integers. The special product of each i-th integer
// in this array is defined as the product of the following:
//
// LeftSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] (i>j).
// If multiple A[j]’s are present in multiple positions, the LeftSpecialValue is the maximum value of j.
//
// RightSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] (j>i).
// If multiple A[j]s are present in multiple positions, the RightSpecialValue is the minimum value of j.
//
// Write a program to find the maximum special product of any integer in the array.
//
// Input: You will receive array of integers as argument to function.
//
// Return: Maximum special product of any integer in the array modulo 1000000007.

// HINT: SOLVE USING STACK FOR BETTER TIME COMPLEXITY

int maxSpecialProduct(vector<int> &A) {
    int n = A.size();
    vector<int> lsv(n);
    vector<int> rsv(n);
    stack<pair<int,int>> s;
    s.push({A[0],0});
    // cout<<s.top().first<<"  "<<s.top().second<<endl;
    //left speacial val
    for(int i=1; i<n; i++){
        while(!s.empty()){
            // cout<<A[i]<<endl;
            if(s.top().first > A[i] ){
                lsv[i] = s.top().second;
                break;
            }
            s.pop();
        }
        s.push({A[i],i});
    }
    // for(int x: lsv){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    while(!s.empty()) s.pop();
    s.push({A[n-1],n-1});
    //right special value
    for(int i=n-2; i>-1; i--){
        while(!s.empty()){
            if(s.top().first > A[i] ){
                rsv[i] = s.top().second;
                break;
            }
            s.pop();
        }
        s.push({A[i],i});
    }

    // for(int x: rsv){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    long long maxVal = lsv[0]*rsv[0];
    for(int i=1; i<n; i++){
        long long v = ((long long)lsv[i]*(long long)rsv[i]);
        // cout<<maxVal<<"  "<<v<<endl;
        maxVal = max(maxVal, v);
    }
    // cout<<"MaxVal : "<<maxVal<<endl;
    return maxVal%1000000007;
}

// Time Complexity : O(4*n) ~ O(n)
// Space Complexity : O(3*n) ~ O(n)
