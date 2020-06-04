// Input: A = [4,5,0,-2,-3,1], K = 5
// Output: 7
// Explanation: There are 7 subarrays with a sum divisible by K = 5:
// [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

int subarraysDivByK(vector<int>& A, int k) {
        unordered_map<int,int> um;
        vector<int> prefixSum(A.size());
        prefixSum[0] = A[0];
        um[0] = 1;
        for(int i=1; i<A.size(); i++)
            prefixSum[i] = prefixSum[i-1] + A[i];
        int count = 0;
        for(int sum : prefixSum){
            int y = (sum%k+k)%k;
            if(um.find(y) != um.end())
                count += um[y];
            um[y]++;
        }
        return count;
    }
