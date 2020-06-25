// Example 1:
//
// Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
// Output: 8
// Explanation: There are 8 negatives number in the matrix.
// Example 2:
//
// Input: grid = [[3,2],[1,0]]
// Output: 0
// Example 3:
//
// Input: grid = [[1,-1],[-1,-1]]
// Output: 3
// Example 4:
//
// Input: grid = [[-1]]
// Output: 1


int binarysearch(vector<int> nums){
    int low=0;
    int high=nums.size()-1;

    while(low<high)
    {
        int mid=low+(high-low)/2;
        if(nums[mid]<0)
            high=mid;
        else
            low=mid+1;
    }

    if(nums[low]<0)
        return nums.size()-low;
    else
        return 0;
}
int countNegatives(vector<vector<int>>& grid)
{
    int n =grid.size();
    int m=grid[0].size();

    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=binarysearch(grid[i]);
    }

    return sum;
}
