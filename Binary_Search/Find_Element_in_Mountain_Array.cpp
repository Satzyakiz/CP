// Example 1:
//
// Input: array = [1,2,3,4,5,3,1], target = 3
// Output: 2
// Explanation: 3 exists in the array, at index=2 and index=5.
// Return the minimum index, which is 2.
// Example 2:
//
// Input: array = [0,1,2,4,2,1], target = 3
// Output: -1
// Explanation: 3 does not exist in the array, so we return -1.
//

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peakIndex = -1;
        int n = mountainArr.length();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            int next = (mid+1)%n;
            if(mountainArr.get(mid) > mountainArr.get(next)){
                peakIndex = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        low = 0, high = peakIndex;
        int minIndex = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(mountainArr.get(mid) == target){
                minIndex = mid;
                high = mid-1;
            }else if(mountainArr.get(mid) > target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        if(minIndex != -1)
            return minIndex;

        low = peakIndex+1, high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(mountainArr.get(mid) == target){
                minIndex = mid;
                high = mid-1;
            }else if(mountainArr.get(mid) < target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return minIndex;
    }
