// Given n non-negative integers a1, a2, ..., an , where each represents a 
// point at coordinate (i, ai). n vertical lines are drawn such that the two
// endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
// with x-axis forms a container, such that the container contains the most water.

// Input: [1,8,6,2,5,4,8,3,7]
// Output: 49

int Solution::maxArea(vector<int> &A) {
    int l = 0, h = A.size()-1;
    int water = 0;
    while(l < h){
      int height = min(A[l],A[h]);
      water = max(water,(h-l)*height);
      while(l<h && A[l] <= height) l++;
      while(l<h && A[h] <= height) h--;
    }
    return water;
}
