// Example 1:
//
// Input: "III"
// Output: 3
// Example 2:
//
// Input: "IV"
// Output: 4
// Example 3:
//
// Input: "IX"
// Output: 9
// Example 4:
//
// Input: "LVIII"
// Output: 58
// Explanation: L = 50, V= 5, III = 3.
// Example 5:
//
// Input: "MCMXCIV"
// Output: 1994
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.


int romanToInt(string s) {
    unordered_map<char, int> um;
    um['I'] = 1;
    um['V'] = 5;
    um['X'] = 10;
    um['L'] = 50;
    um['C'] = 100;
    um['D'] = 500;
    um['M'] = 1000;
    int n = s.size(),i=0;
    int ans = um[s[n-1]];
    for(int i=n-2; i>=0; i--){
        if(um[s[i]]  < um[s[i+1]]){
            ans -= um[s[i]];
        }else{
            ans += um[s[i]];
        }
    }
    return ans;
}
