// You are given a string s that consists of lower case English letters
// and brackets.
//
// Reverse the strings in each pair of matching parentheses,
// starting from the innermost one.
//
// Your result should not contain any brackets.
//
//
//
// Example 1:
//
// Input: s = "(abcd)"
// Output: "dcba"
// Example 2:
//
// Input: s = "(u(love)i)"
// Output: "iloveu"
// Explanation: The substring "love" is reversed first, then the whole
// string is reversed.
// Example 3:
//
// Input: s = "(ed(et(oc))el)"
// Output: "leetcode"
// Explanation: First, we reverse the substring "oc", then "etco", and
// finally, the whole string.
// Example 4:
//
// Input: s = "a(bcdefghijkl(mno)p)q"
// Output: "apmnolkjihgfedcbq"

string reverseParentheses(string s) {
    stack<string> stk;
    string ans = "";
    for(char &c: s){
        if(stk.empty() && c != '('){
            ans += c;
        }else if(c != ')'){
            string z(1,c);
            stk.push(z);
        }else{
            string temp = "";
            while(!stk.empty() && stk.top() != "("){
                string z = stk.top();
                reverse(z.begin(),z.end());
                temp += z;
                stk.pop();
            }
            if(!stk.empty())
                stk.pop();
            if(stk.empty()){
                ans += temp;
            }else{
                stk.push(temp);
            }
        }
    }
    return ans;
}
