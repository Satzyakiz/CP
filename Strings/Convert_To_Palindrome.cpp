// Given a string A consisting only of lowercase characters,
// we need to check whether it is possible to make this string a palindrome
// after removing exactly one character from this.
//
// If it is possible then return 1 else return 0.

// Input 1:
//
//  A = "abcba"
// Input 2:
//
//  A = "abecbea"
//
// Output 1:
//
//  1
// Output 2:
//
//  0

int Solution::solve(string A) {
    int n = A.size();
    int i=0, j=n-1,c=0;
    while(i < j){
        if(A[i] == A[j]){
            i++,j--;
        }else if(A[i+1] == A[j]){
            i++;
            c++;
        }else if(A[i] == A[j-1]){
            j--;
            c++;
        }else{
            return 0;
        }
    }
    if(c > 1)
        return 0;
    return 1;
}
