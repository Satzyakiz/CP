// Given an array nums of n integers, are there elements a, b, c in nums
// such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
// Given array nums = [-1, 0, 1, 2, -1, -4],
//
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]

vector<vector<int>> getDistinctNos(vector<int> arr){
  int n=arr.size();
  vector<vector<int>> ans;
  if(n < 3) return ans;
  sort(arr.begin(), arr.end());
  for(int i=0, i<n-2; i++){
    int target = -arr[i];
    int j=i+1, k=n-1;
    while(j<k){
      if(arr[j]+arr[k] > target) k--;
      else if(arr[j]+arr[k] < target) j++;
      else{
        vector<int> v{arr[i],arr[j],arr[k]};
        ans.emplace_back(v);
        while( k > j && nums[j] == nums[j+1]) j++; //Avoid similar set in a particular loop
        j++;
      }
    }
  }
  sort(ans.begin(),ans.end());
  ans.erase(unique(ans.begin(),ans.end()),ans.end());
  return ans;
}
