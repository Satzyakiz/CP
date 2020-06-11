
// Input: [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

void sortColors(vector<int>& nums) {
        int c0,c1,c2;
        c0 = c1 = c2 = 0;
        for(int x: nums){
            if(x == 0) c0++;
            else if(x == 1) c1++;
            else if(x == 2) c2++;
        }
        int i =0;
        while(c0--){
            nums[i++] = 0;
        }
        while(c1--){
            nums[i++] = 1;
        }
        while(c2--){
            nums[i++] = 2;
        }
    }
