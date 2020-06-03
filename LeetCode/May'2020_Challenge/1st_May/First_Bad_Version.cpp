
// Given n = 5, and version = 4 is the first bad version.
//
// call isBadVersion(3) -> false
// call isBadVersion(5) -> true
// call isBadVersion(4) -> true
//
// Then 4 is the first bad version.

int firstBadVersion(int n) {
        long long low = 1,high = n,mid;
        long long ans;
        while(low<=high){
            mid = low + (high-low)/2;
            if(isBadVersion(mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return (int)ans;
    }
