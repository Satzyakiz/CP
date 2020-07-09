// Given a number A in a form of string.
//
// You have to find the smallest number that has same set of digits
// as A and is greater than A.
//
// If A is the greatest possible number with its set of digits, then return -1.

// Input 1:
//
//  A = "218765"
// Input 2:
//
//  A = "4321"
//
// Output 1:
//
//  "251678"
// Output 2:
//
//  "-1"

bool maxNo(string A){
    string B = A;
    sort(B.rbegin(),B.rend());
    return B == A;
}
string Solution::solve(string A) {
    if(maxNo(A))
        return "-1";
    next_permutation(A.begin(),A.end());
    return A;
}

//Without inbuilt function
bool maxNo(string A){
    string B = A;
    sort(B.rbegin(),B.rend());
    return B == A;
}
string Solution::solve(string A) {
    if(maxNo(A))
        return "-1";
    int i = A.size() - 1;

    while(i>0 && A[i] <= A[i-1]){
        i--;
    }
    char c = A[i];
    int index = i;
    for(int j=i+1; j<A.size(); j++){
        if(A[j] > A[i-1] && A[j] < c){
           c = A[j];
           index = j;
        }
    }
    swap(A[i-1],A[index]);
    sort(A.begin()+i,A.end());
    return A;
}
