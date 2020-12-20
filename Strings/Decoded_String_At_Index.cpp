// An encoded string S is given.
// To find and write the decoded string to a tape, the encoded string
// is read one character at a time and the following steps are taken:
//
// If the character read is a letter, that letter is written onto the tape.
// If the character read is a digit (say d), the entire current tape is
// repeatedly written d-1 more times in total.
// Now for some encoded string S, and an index K, find and return the
// K-th letter (1 indexed) in the decoded string.
//
//
//
// Example 1:
//
// Input: S = "leet2code3", K = 10
// Output: "o"
// Explanation:
// The decoded string is "leetleetcodeleetleetcodeleetleetcode".
// The 10th letter in the string is "o".
// Example 2:
//
// Input: S = "ha22", K = 5
// Output: "h"
// Explanation:
// The decoded string is "hahahaha".  The 5th letter is "h".
// Example 3:
//
// Input: S = "a2345678999999999999999", K = 1
// Output: "a"
// Explanation:
// The decoded string is "a" repeated 8301530446056247680 times.
// The 1st letter is "a".

string decodeAtIndex(string S, int K) {
    long long size = 0;
    for(int i=0; i<S.size(); i++){
        if(isdigit(S[i]))
            size *= (S[i] - '0');
        else
            size++;
    }

    for(int i=S.size() - 1; i >= 0; i--){
        K %= size;
        if(K == 0 && isalpha(S[i])) return string(1, S[i]);
        if(isdigit(S[i]))
            size /= (S[i] - '0');
        else
            size--;
    }
    return S.substr(K,1);
}

// Approach:
// Building the string would lead to Memory Limit Exceeded.
// So we just need to calculate the size and check.
// let ab2cd2 be the case and K = 7.
// ab2cd2 = ababcdababcd and 7th character is 'a'
// Iteration 1:
// Size = 12 and K = 7. K %= Size will be 7 and size would decrease by 2 i.e 6
// Itr2 :
// Size = 6, K = 7, K %= Size will be 1 and size will become 5.
// .
// .
// .
// When size = 1, K = 1 and k %= Size will be 0 and first character is an
// alphabet and it is our answer
