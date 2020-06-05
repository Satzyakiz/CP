// All nos appear 3 times except one no.


//Using BIT Manipulation 0(1) space
int getNumber(vector<int> nums){
  int one = 0, two = 0;
  for(int x: nums){
    one = (one ^ x) & ~two;
    two = (two ^ x) & ~one;
  }
  return one;
}

//Using Mathematical Solution
// (3 * sum(set(nums)) - sum(nums)) / 2
//sum(set(nums)): will give sum of unique elements and 3 is multiplied
// to get the sum of each of unique elements 3 times
// when sum(nums) is subtracted, 2 * our_req_no is left
//so we divide by 2
int getNumber(vector<int> nums){
  int sum = 0;
  set<int> s;
  for(int x: nums) {
    sum += x;
    s.insert(x);
  }
  int set_sum = 0;
  for(int x: set){
    set_sum += x;
  }
  return (3*set_sum - sum)/2;
}



}
