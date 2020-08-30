// Given a non-empty array of unique positive integers A, consider 
// the following graph:
//
// There are A.length nodes, labelled A[0] to A[A.length - 1];
// There is an edge between A[i] and A[j] if and only if A[i] and A[j]
// share a common factor greater than 1.
// Return the size of the largest connected component in the graph.
//
// Input: [4,6,15,35]
// Output: 4
//
// Input: [20,50,9,63]
// Output: 2
//
// Input: [2,3,6,7,4,12,21,39]
// Output: 8

int parent[100001];
int find(int x){
    if(parent[x] != -1){
        return parent[x] = find(parent[x]);
    }else
        return x;
}
void unionn(int x,int y){
    int xp = find(x), yp = find(y);
    if(xp != yp){
        parent[yp] = xp;
    }
}
int largestComponentSize(vector<int>& A) {
    memset(parent, -1, sizeof(parent));
    for(int &x: A){
        for(int i=2; i*i <= x; i++){
            if(x % i == 0){
                unionn(i,x);
                unionn(x,x/i);
            }
        }
    }
    unordered_map<int,int> um;
    int ans = 0;
    for(int &x: A){
        ans = max(ans, ++um[find(x)]);
    }
    return ans;
}
