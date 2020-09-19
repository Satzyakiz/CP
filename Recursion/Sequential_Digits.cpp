// An integer has sequential digits if and only if each digit in 
// the number is one more than the previous digit.
//
// Return a sorted list of all the integers in the range [low, high]
// inclusive that have sequential digits.
//
//
//
// Example 1:
//
// Input: low = 100, high = 300
// Output: [123,234]
// Example 2:
//
// Input: low = 1000, high = 13000
// Output: [1234,2345,3456,4567,5678,6789,12345]

vector<int> ans;
void solve(long long no, int low, int high){

    if(no > high) return;
    if(no >= low && no <= high){
        ans.push_back((int)no);
    }
    int last =  no % 10 + 1;
    if(last > 9) return;
    solve(no*10 + last, low, high);
}
vector<int> sequentialDigits(int low, int high) {
    ans.clear();
    for(int i=1; i<=9; i++)
        solve(i,low, high);
    sort(ans.begin(), ans.end());
    return ans;
}
