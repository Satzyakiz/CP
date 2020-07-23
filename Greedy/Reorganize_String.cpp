// Given a string S, check if the letters can be rearranged so that two 
// characters that are adjacent to each other are not the same.
//
// If possible, output any possible result.  If not possible,
// return the empty string.
//
// Example 1:
//
// Input: S = "aab"
// Output: "aba"
// Example 2:
//
// Input: S = "aaab"
// Output: ""

string reorganizeString(string S) {
    int n = S.size();
    vector<char> v(n);
    unordered_map<char,int> um;
    for(char &c: S){
        um[c]++;
    }
    priority_queue<pair<int,char>> pq;
    for(auto itr = um.begin(); itr != um.end(); itr++){
        pq.push({itr->second,itr->first});
    }
    int top = pq.top().first;
    if(n % 2 == 0){
        if(top > n/2)
            return "";
    }else{
        if(top > n/2+1)
            return "";
    }
    S = "";
    while(!pq.empty()){
        int t = pq.top().first;
        char ch = pq.top().second;
        pq.pop();
        for(int i=0; i<t; i++)
            S += ch;
    }
    int j = 0;
    for(int i=0,flag = false; i<n; i+=2){
        v[i] = S[j++];
        if(i+2 >= n){
            if(flag == false){
                i = -1;
                flag = true;
            }
        }
    }
    string ans = "";
    for(char &c: v)
        ans += c;
    return ans;
}
