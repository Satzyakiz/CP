// Given n non-negative integers representing an elevation map where the width
// of each bar is 1, compute how much water it is able to trap after raining.
//
// Example:
//
// Input: [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6

//We will take help of 2 arrays, one is leftMax and other is rightMax.
// leftMax[] : Will hold the max height of towers to its left
// rightMax[] : Will hold the max height of towers to its right
// Then min height among leftMax[i] and rightMax[i] will be considered
// The height of ith element needs to be subtracted from the minimum

int rainWaterTrapped(vector<int> height){
  int n = height.size();
  vector<int> leftMax(n),rightMax(n);
  leftMax[0] = height[0];
  for(int i=1; i<n; i++){
    //Calculating maxHeight among current height and previous maxHeight
    leftMax[i] = max(leftMax[i-1],height[i]);
  }
  rightMax[n-1] = height[n-1];
  for(int i=n-2; i>=0; i--){
      rightMax[i] = max(rightMax[i+1],height[i]);
  }

  int ans = 0;
  for(int i=0; i<n; i++){
      ans += min(leftMax[i],rightMax[i]) - height[i];
  }
  return ans;
}
