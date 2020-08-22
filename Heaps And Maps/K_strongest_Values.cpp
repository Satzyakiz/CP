// 
// Given an array of integers arr and an integer k.
//
// A value arr[i] is said to be stronger than a value arr[j] if
// |arr[i] - m| > |arr[j] - m| where m is the median of the array.
// If |arr[i] - m| == |arr[j] - m|, then arr[i] is said to be stronger than
// arr[j] if arr[i] > arr[j].
//
// Return a list of the strongest k values in the array. return the answer
// in any arbitrary order.
//
// Median is the middle value in an ordered integer list. More formally,
// if the length of the list is n, the median is the element in position
// ((n - 1) / 2) in the sorted list (0-indexed).
//
// Example 1:
//
// Input: arr = [1,2,3,4,5], k = 2
// Output: [5,1]
// Explanation: Median is 3, the elements of the array sorted by
// the strongest are [5,1,4,2,3]. The strongest 2 elements are [5, 1].
// [1, 5] is also accepted answer.
// Please note that although |5 - 3| == |1 - 3| but 5 is stronger than 1
// because 5 > 1.
// Example 2:
//
// Input: arr = [1,1,3,5,5], k = 2
// Output: [5,5]
// Explanation: Median is 3, the elements of the array sorted by the
// strongest are [5,5,1,1,3]. The strongest 2 elements are [5, 5].
// Example 3:
//
// Input: arr = [6,7,11,7,6,8], k = 5
// Output: [11,8,6,6,7]
// Explanation: Median is 7, the elements of the array sorted by the
// strongest are [11,8,6,6,7,7].
// Any permutation of [11,8,6,6,7] is accepted.
// Example 4:
//
// Input: arr = [6,-3,7,2,11], k = 3
// Output: [-3,11,2]
// Example 5:
//
// Input: arr = [-7,22,17,3], k = 2
// Output: [22,17]

struct Compare{
    bool operator()(const pair<int,int> &p1, const pair<int,int> &p2){
        if(p1.first == p2.first)
            return p1.second > p2.second;
        return p1.first > p2.first;
    }
};
vector<int> getStrongest(vector<int>& arr, int k) {
    sort(arr.begin(),arr.end());
    int n = arr.size();
    int m = arr[(n-1)/2];
    priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;
    for(int &x: arr){
        int d = abs(x-m);
        pq.push({d,x});
        if(pq.size() > k)
            pq.pop();
    }
    vector<int> ans;
    while(!pq.empty()){
        ans.emplace_back(pq.top().second);
        // cout<<pq.top().second<<endl;
        pq.pop();
    }
    return ans;
}
