// Given an array of integers, find two numbers such that they add up to a specific target number.
// If multiple solutions exist, output the one where index2 is minimum. If there are multiple solutions with
// the minimum index2, choose the one with minimum index1 out of them.
// Input: [2, 7, 11, 15], target=9
// Output: index1 = 1, index2 = 2
vector<int> Solution::twoSum(const vector<int> &A, int B) {
    unordered_map<int,int> um;
    um[A[0]] = 1;
    for(int i=1; i<A.size(); i++){
        //check if the difference exists in the map and whether its index is
        //less than the other index i.e. of A[i].
        if(um.find(B-A[i]) != um.end() && um[B-A[i]] < i+1 ){
            vector<int> ans{um[B-A[i]],i+1};
            return ans;
        }
        else{
            //IF the element is already present in the list, no need to modify it
            //as it already contains the least index.
            if(um.find(A[i]) == um.end()){
                um[A[i]] = i+1;
            }
        }
    }
    return {};
}
