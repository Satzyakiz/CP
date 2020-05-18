
int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        int sum = 0,count=0;
        for(int x: nums){
            sum += x;
            if(sum == k)
              count++;

              //If the sum is already found, then it means
              //there is a subarray whose value is equal to k
              //which resulted in getting the same sum back
            if(um.find(sum - k) != um.end())
              count+=um[sum-k];

            um[sum]++;
        }
        return count;
}
