// Given a string s, you are allowed to convert it to a palindrome by
// adding characters in front of it. Find and return the shortest
// palindrome you can find by performing this transformation.
//
// Example 1:
//
// Input: "aacecaaa"
// Output: "aaacecaaa"
// Example 2:
//
// Input: "abcd"
// Output: "dcbabcd"

//Using KMP pattern matching algorithm

string shortestPalindrome(string s) {
    string revS = s;
    reverse(revS.begin(), revS.end());
    int n = s.size(),j,i;
    string newS = s + "#" + revS;

    vector<int> partial(newS.size());

    for(i=1; i<newS.size(); i++){
        j = partial[i-1];
        while(j >  0 && newS[i] != newS[j])
            j = partial[j-1];

        if(newS[i] == newS[j])
            partial[i] = j+1;
    }
    string ans = revS.substr(0, n - partial[newS.size()-1]) + s;
    return ans;
}
