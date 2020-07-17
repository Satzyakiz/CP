// Given an integer array A and two integers B and C.
//
// You need to find the number of subarrays in which the number
// of occurrences of B is equal to number of occurrences of C.
//
// NOTE: Don't count empty subarrays.

int Solution::solve(vector<int> &A, int B, int C) {
    int n = A.size();
    auto itr1 = find(A.begin(),A.end(),B);
    auto itr2 = find(A.begin(),A.end(),C);
    if(itr1 == A.end() && itr2 == A.end()){
        return n*(n+1)/2;
    }
    vector<int> X(n), Y(n);
    int count=0,i=0;
    for(int &x: A){
        if(x == B){
            count++;
        }
        X[i++] = count;
    }
    count=0,i=0;
    for(int &x: A){
        if(x == C){
            count++;
        }
        Y[i++] = count;
    }
    vector<int> diff(n);
    for(int i=0; i<n; i++){
        diff[i] = abs(X[i] - Y[i]);
    }
    unordered_map<int,int> um;
    for(int &x: diff)
        um[x]++;

    int result = um[0];
    for (auto it = um.begin(); it != um.end(); it++)
        result = result + ((it->second) * ((it->second) - 1)) / 2;

    return (result);
}
