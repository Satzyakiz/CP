
// Given a non-empty array of integers, return the k 
// most frequent elements.
//
// Example 1:
//
// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:
//
// Input: nums = [1], k = 1
// Output: [1]

vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        for(int x: nums)
            um[x]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        for(auto i=um.begin(); i!=um.end(); i++){
            minHeap.push({i->second,i->first});
            if(minHeap.size() > k)
                minHeap.pop();
        }
        vector<int> ans;
        while(!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
