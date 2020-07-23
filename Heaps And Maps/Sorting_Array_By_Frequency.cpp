// Given an array of integers, sort the array according to frequency of
// elements. That is elements that have higher frequency come first. If
// frequencies of two elements are same, then smaller number comes first.

// Input:
// 2
// 5
// 5 5 4 6 4
// 5
// 9 9 9 2 5
// Output:
// 4 4 5 5 6
// 9 9 9 2 5

struct Compare{
    bool operator()(pair<int,int> p1, pair<int,int> p2){
        if(p1.first == p2.first)
            return p1.second > p2.second;
        return p1.first < p2.first;
    }
};
vector<int> sortByFreq(int arr[],int n)
{
    //Your code here
    priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
    unordered_map<int,int> um;
    for(int i=0; i<n; i++)
        um[arr[i]]++;

    for(auto itr = um.begin(); itr != um.end(); itr++){
        pq.push({itr->second,itr->first});
    }

    vector<int> ans;
    while(!pq.empty()){
        int k = pq.top().first, no = pq.top().second;
        pq.pop();
        while(k--)
            ans.push_back(no);
    }
    return ans;
}
