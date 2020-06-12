
// A=[1, 2, 1, 3, 4, 3] and K = 3
//
// All windows of size K are
//
// [1, 2, 1]
// [2, 1, 3]
// [1, 3, 4]
// [3, 4, 3]
//
// So, we return an array [2, 3, 3, 2].


vector<int> Solution::dNums(vector<int> &A, int B) {
    unordered_map<int,int> um;
    for(int i=0; i<B; i++){
        um[A[i]] += 1;
    }
    vector<int> ans;
    for(int i=B; i<=A.size(); i++){
        ans.emplace_back(um.size());
        if(um[A[i-B]] == 1){
            um.erase(A[i-B]);
        }else{
            um[A[i-B]]--;
        }
        um[A[i]]++;
    }
    return ans;
}
