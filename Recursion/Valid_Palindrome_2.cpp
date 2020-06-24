// Given a non-empty string s, you may delete at most one character. 
// Judge whether you can make it a palindrome.
//
// Example 1:
// Input: "aba"
// Output: True
// Example 2:
// Input: "abca"
// Output: True
// Explanation: You could delete the character 'c'.

bool validPalindrome(string s) {
    return check(s,0,s.size()-1,0);
}
bool check(string &s,int i,int j,int count){
    if(count > 1)
        return false;
    if(i >= j)
        return true;
    if(s[i] != s[j]){
        return check(s,i+1,j,count+1) || check(s,i,j-1,count+1);
    }

    return check(s,i+1,j-1,count);
}
