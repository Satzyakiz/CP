// Given an array A of integers and another non negative integer k,
// find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.
//
// Example :
//
// Input :
//
// A : [1 5 3]
// k : 2
// Output :
// 1
// Return 0 / 1 for this problem.

int Solution::diffPossible(const vector<int> &A, int k) {

unordered_map<int,int> umap;

for(int i=0;i<A.size();i++)
{
    int sum1=A[i]+k;
    int sum2=A[i]-k;

    if(umap.count(sum1)!=0||umap.count(sum2)!=0)
     return 1;

    umap[A[i]]=1;
}
return 0;
}
