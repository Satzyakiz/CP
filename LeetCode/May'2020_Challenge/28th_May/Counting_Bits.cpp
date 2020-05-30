

// Given a non negative integer number num.
// For every numbers i in the range 0 ≤ i ≤ num calculate
// the number of 1's in their binary representation and
// return them as an array.
//
// Example 1:
//
// Input: 2
// Output: [0,1,1]
// Example 2:
//
// Input: 5
// Output: [0,1,1,2,1,2]


vector<int> countBits(int num) {
        if(num == 0) return {0};
        vector<int> ans(num+1,0);
        ans[0] = 0;
        ans[1] = 1;
        int flag = 1;
        for(int i=2; i<=num; i++){
            if((i&(i-1)) == 0){
                flag *= 2;
            }
            ans[i] = ans[i-flag]+1;
        }
        return ans;
    }
