IP:
5
3 7 4 6 5
OP:
13

IP:
5
3 5 -7 8 10
OP:
15

int maxSubsetSum(vector<int> nums) {
    if(nums.size() == 0)
        return 0;
    int excludeCurrent = 0, includeCurrent = nums[0];
    for(int i=1; i<nums.size(); i++){
        int temp = includeCurrent;
        includeCurrent = max(excludeCurrent + nums[i], includeCurrent);
        excludeCurrent = max(temp,excludeCurrent);
    }
    return max(includeCurrent,excludeCurrent);
}
