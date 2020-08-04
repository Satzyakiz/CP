
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given
// number of rows like this: (you may want to display this pattern in a
//     fixed font for better legibility)
//
// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"
//
// Write the code that will take a string and make this conversion given
// a number of rows:
//
// string convert(string s, int numRows);
// Example 1:
//
// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
// Example 2:
//
// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
//
// P     I    N
// A   L S  I G
// Y A   H R
// P     I


string convert(string A, int B) {
    if(B == 1)
        return A;
    int len = A.size();
    vector<string> arr(B);
    bool down;
    int row = 0;
    for(int i=0; i<len; i++){
        arr[row].push_back(A[i]);
        if(row == B-1)
            down = false;
        else if(row == 0)
            down = true;

        down ? row++ : row--;
    }
    string ans = "";
    for(string &s: arr)
        ans += s;
    return ans;
}
