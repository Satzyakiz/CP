// Given an array of integers nums and a positive integer k,
// find whether it's possible to divide this array into k non-empty
// subsets whose sums are all equal.
//
//
//
// Example 1:
//
// Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
// Output: True
// Explanation: It's possible to divide it into 4 subsets
// (5), (1, 4), (2,3), (2,3) with equal sums.

bool helper(vector<int> &nums,int k, int targetSum,
            vector<bool> &visited,int currSubsetSum,int nextIndex){
    if(k == 0) //All k subsets satisfy the req sum property
        return true;
    if(currSubsetSum == targetSum){
        //One subset is satisfied
        //Check for next k-1 subsets
        return helper(nums,k-1,targetSum,visited,0,0);
    }

    for(int i=nextIndex; i<nums.size(); i++){
        if( !visited[i] && currSubsetSum + nums[i] <= targetSum ){
            visited[i] = true;
            //Chcek until that particular subset fulfills the condition
            //so k is same
            if( helper(nums,k,targetSum,visited,currSubsetSum + nums[i], i+1) )
                return true;
            visited[i] = false;
        }
    }
    return false;
}

bool partitionKEqualSubsets(vector<int> nums,int k){
    int sum = 0, maxItem = 0;
    for(int x: nums){
        sum += x;
        maxItem = max(maxItem,x);
    }
    //If sum is not divisible by k, it cannot be divided into k equal subsets
    //If maxItem > sum/k, one subset will have greater than req. val and
    // another would have less than req val
    if(sum % k != 0 || maxItem > sum / k)
        return false;
    //Visited vector: To keep in check that same item is not in multiple sets
    vector<bool> visited(nums.size(),false);
    return helper(nums,k,sum/k,visited,0,0);
}
