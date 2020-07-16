// Given an array containing 0s and 1s.
// Find the number of subarrays having equal number of 0s and 1s.
// Input:
// 2
// 7
// 1 0 0 1 0 1 1
// 5
// 1 1 1 1 0
// Output:
// 8
// 1
//
// Explanation:
// Testcase 1: The index range for the 8 sub-arrays are:
// (0, 1), (2, 3), (0, 3), (3, 4), (4, 5)
// (2, 5), (0, 5), (1, 6)
// Testcase 2: The index range for the subarray is (3,4).

//Convert 0 to -1 and problem changes to 0 sum subarray

long long int countSubarrWithEqualZeroAndOne(int arr[], int N)
{
    //Your code here
    for(int i=0; i<N; i++){
        if(arr[i] == 0)
            arr[i] = -1;
    }
    int sum = 0;
    int ans = 0;
    unordered_map<int,long> um;
    for(int i=0; i<N; i++){
        sum += arr[i];
        if(sum == 0)
            ans++;
        if(um.find(sum) != um.end()){
            ans += um[sum];
        }

        um[sum]++;
    }
    return ans;
}
