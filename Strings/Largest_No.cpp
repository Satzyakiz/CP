// Given a list of non negative integers, arrange them such that they
// form the largest number.
//
// Example 1:
//
// Input: [10,2]
// Output: "210"
// Example 2:
//
// Input: [3,30,34,5,9]
// Output: "9534330"
// Note: The result may be very large, so you need to return a string
// instead of an integer.

static bool Comp(string &s1, string &s2){
    return s1+s2 > s2+s1;
}
string largestNumber(vector<int>& nums) {
    vector<string> v;
    for(int x: nums){
        v.emplace_back(to_string(x));
    }
    sort(v.begin(),v.end(),Comp);
    string ans = "";
    for(string s: v)
        ans += s;
    while(ans[0] == '0' && ans.size() > 1)
        ans.erase(0,1);
    return ans;
}
