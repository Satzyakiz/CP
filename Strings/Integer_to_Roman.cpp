
// Example 1:
//
// Input: 3
// Output: "III"
// Example 2:
//
// Input: 4
// Output: "IV"
// Example 3:
//
// Input: 9
// Output: "IX"
// Example 4:
//
// Input: 58
// Output: "LVIII"
// Explanation: L = 50, V = 5, III = 3.
// Example 5:
//
// Input: 1994
// Output: "MCMXCIV"
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.


string intToRoman(int num) {
    vector<string> roman {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    vector<int> no {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string ans = "";
    for(int i=0; num != 0; i++){
        while(num >= no[i]){
            num -= no[i];
            ans += roman[i];
        }
    }
    return ans;
}
