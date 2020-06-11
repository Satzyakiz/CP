// Input:  [1,2,3,4]   , [0,0] , [0,1]
// Output: [24,12,8,6] , [0,0] , [1,0]

vector<int> productExceptSelf(vector<int>& nums) {

        int n=nums.size();
        int fromBegin=1;
        int fromLast=1;
        vector<int> res(n,1);

        for(int i=0;i<n;i++){
            res[i]*=fromBegin;
            fromBegin*=nums[i];
            res[n-1-i]*=fromLast;
            fromLast*=nums[n-1-i];
        }
        return res;
    }
