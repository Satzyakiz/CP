// Given a non-empty string check if it can be constructed by taking a
// substring of it and appending multiple copies of the substring together.
// You may assume the given string consists of lowercase English letters only
// and its length will not exceed 10000.

// Example 1:
//
// Input: "abab"
// Output: True
// Explanation: It's the substring "ab" twice.
// Example 2:
//
// Input: "aba"
// Output: False
// Example 3:
//
// Input: "abcabcabcabc" (Try this input to get the idea)
// Output: True
// Explanation: It's the substring "abc" four times.
// (And the substring "abcabc" twice.)

bool repeatedSubstringPattern(string str) {
    int n = str.length();
    for (int i = 1; i <= n / 2; i++)
        if (n % i == 0 && str.substr(i) == str.substr(0, n - i))
            return true;
    return false;
}

//n%i is required as the substring length should divide the string length
//in order to make total substrings of same size
