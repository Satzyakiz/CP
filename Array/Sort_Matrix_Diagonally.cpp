// Given a m * n matrix mat of integers, sort it diagonally in 
// ascending order from the top-left to the bottom-right then return
// the sorted array.
//
// Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
// Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]


vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    unordered_map<int,vector<int>> um;
    int m = mat.size(), n = mat[0].size();
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            um[j-i].push_back(mat[i][j]);
        }
    }

    for(auto itr = um.begin(); itr != um.end(); itr++)
        sort(itr->second.begin(), itr->second.end());

    for(int i = m-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            mat[i][j] = um[j-i].back();
            um[j-i].pop_back();
        }
    }

    return mat;
}
