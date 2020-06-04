
// Example 1:
//
// Input: n = 3, k = 3
// Output: "213"
// Example 2:
//
// Input: n = 4, k = 9
// Output: "2314"

string getPermutation(int n, int k) {
        string s;
        for(int i=1; i<=n; i++){
            s+=i+'0';
        }
        if(k == 1)
            return s;
        while(k > 1){
            next_permutation(s.begin(),s.end());
            k--;
        }
        return s;
    }
