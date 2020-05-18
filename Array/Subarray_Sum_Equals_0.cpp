

int subarraySum(vector<int>& nums) {
        unordered_map<int,int> um;
        int sum = 0,count=0;
        for(int x: nums){
            sum += x;
            if(sum == 0)
              count++;
            //If the sum is already found, then it means
            //there is a subarray whose value is equal to 0
            //which resulted in getting the same sum back
            if(um.find(sum) != um.end())
              count+=um[sum];

            um[sum]++;
        }
        return count;
    }
