// Given a sorted array arr, two integers k and x,
// find the k closest elements to x in the array.
// The result should also be sorted in ascending order.
// If there is a tie, the smaller elements are always preferred.
//
//
//
// Example 1:
//
// Input: arr = [1,2,3,4,5], k = 4, x = 3
// Output: [1,2,3,4]
// Example 2:
//
// Input: arr = [1,2,3,4,5], k = 4, x = -1
// Output: [1,2,3,4]

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> maxHeap;
        for(int e: arr){
            maxHeap.push({abs(x-e),e});
            if(maxHeap.size() > k)
                maxHeap.pop();
        }
        vector<int> ans;
        while(!maxHeap.empty()){
            ans.emplace_back(maxHeap.top().second);
            maxHeap.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
