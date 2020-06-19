// Given a column title as appear in an Excel sheet, return its
// corresponding column number.
//
// For example:
//
//     A -> 1
//     B -> 2
//     C -> 3
//     ...
//     Z -> 26
//     AA -> 27
//     AB -> 28
//     ...
// Example 1:
//
// Input: "A"
// Output: 1
// Example 2:
//
// Input: "AB"
// Output: 28
// Example 3:
//
// Input: "ZY"
// Output: 701

    int titleToNumber(string s) {
        int col = 0;
        for(char c: s){
            col = col * 26 + (c - 'A'+1);
        }
        return col;
    }
