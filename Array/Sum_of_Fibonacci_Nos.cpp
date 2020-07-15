// How many minimum numbers from fibonacci series are required such
// that sum of numbers should be equal to a given Number N?
// Note : repetition of number is allowed.
//
// Example:
//
// N = 4
// Fibonacci numbers : 1 1 2 3 5 .... so on
// here 2 + 2 = 4
// so minimum numbers will be 2

int fibsum(int A) {
    vector<int> fib{1,1};
    for(int i=2; fib[i-1] < A; i++){
        int x = fib[i-1] + fib[i-2];
        if(x == A)
            return 1;
        fib.emplace_back(x);
    }
    int i = fib.size()-1,ans = 0;
    while(A > 0){
        if(fib[i] <= A){
            A -= fib[i];
            ans++;
        }
        i--;
    }
    return ans;
}
