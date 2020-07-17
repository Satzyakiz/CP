// You are given an integer array nums and you have to return a new counts array.
// The counts array has the property where counts[i] is the number of
// smaller elements to the right of nums[i].
//
// Example:
//
// Input: [5,2,6,1]
// Output: [2,1,1,0]
// Explanation:
// To the right of 5 there are 2 smaller elements (2 and 1).
// To the right of 2 there is only 1 smaller element (1).
// To the right of 6 there is 1 smaller element (1).
// To the right of 1 there is 0 smaller element.

// Approach: Divide and Conquer (Merge Sort technique)
// The count of nos, travelling from right subarray to left subarray is the ans

    vector<pair<int,int>> v;
    vector<int> ans;
    vector<int> countSmaller(vector<int>& nums) {
        v.clear();
        for(int i=0; i<nums.size(); i++)
            v.push_back({nums[i],i});
        ans = vector<int>(nums.size());
        merge_sort(0,nums.size()-1);
        return ans;
    }
    void merge_sort(int start,int end){
        if(start < end){
            int mid = start + (end-start)/2;
            merge_sort(start,mid);
            merge_sort(mid+1,end);
            merge(start,mid,mid+1,end);
        }
    }
    void merge(int start1, int end1, int start2, int end2){
        vector<pair<int,int>> temp;
        int p = start1, q = start2;
        while(p <= end1 && q <= end2){
            if(v[p].first <= v[q].first){
                ans[v[p].second] += q - start2;
                temp.push_back(v[p++]);
            }else{
                temp.push_back(v[q++]);
            }
        }
        while(p <= end1){
            ans[v[p].second] += q - start2;
            temp.push_back(v[p++]);
        }
        while(q <= end2){
            temp.push_back(v[q++]);
        }
        for(int i=start1; i<=end2; i++)
            v[i] = temp[i-start1];
    }
