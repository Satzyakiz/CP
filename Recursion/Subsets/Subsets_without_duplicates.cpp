void subset(vector<vector<int>> &ans,vector<int> arr,int size,vector<int> currArr){
    if(size == arr.size()){
        ans.emplace_back(currArr);
        return;
    }
    subset(ans,arr,size+1,currArr);
    vector<int> tempArr(currArr.begin(),currArr.end());
    tempArr.emplace_back(arr[size]);
    subset(ans,arr,size+1,tempArr);
}

vector<vector<int>> subsetsWithDup(vector<int> &A) {
    vector<vector<int>> ans;
    sort(A.begin(),A.end());
    subset(ans,A,0,{});
    //Sorting is necessary for unique, it only removes contiguous duplicates
    sort(ans.begin(),ans.end());
    //The below line erarse the duplicate elements
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    return ans;
}