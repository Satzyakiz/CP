// Input 1:
//
//  A = "abadbc"
// Input 2:
//
//  A = "abcabc"


// Example Output
// Output 1:
//
//  "aabbdd"
// Output 2:
//
//  "aaabc#"
//
//
// Example Explanation
// Explanation 1:
//
//     "a"      -   first non repeating character 'a'
//     "ab"     -   first non repeating character 'a'
//     "aba"    -   first non repeating character 'b'
//     "abad"   -   first non repeating character 'b'
//     "abadb"  -   first non repeating character 'd'
//     "abadbc" -   first non repeating character 'd'
// Explanation 2:
//
//     "a"      -   first non repeating character 'a'
//     "ab"     -   first non repeating character 'a'
//     "abc"    -   first non repeating character 'a'
//     "abca"   -   first non repeating character 'b'
//     "abcab"  -   first non repeating character 'c'
//     "abcabc" -   no non repeating character so '#'

string Solution::solve(string A) {
    vector<int> m(26);
    string ans = "";
    queue<char> q;
    for(char &c: A){
        m[c - 97]++;
        q.push(c);
        while(!q.empty() && m[q.front()-97] > 1){
            q.pop();
        }
        if(q.empty())
            ans += "#";
        else{
            ans += q.front();
        }
    }
    return ans;
}
