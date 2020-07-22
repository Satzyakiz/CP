// Given a balanced parentheses string S, compute the score of the string 
// based on the following rule:
//
// () has score 1
// AB has score A + B, where A and B are balanced parentheses strings.
// (A) has score 2 * A, where A is a balanced parentheses string.
//
//
// Example 1:
//
// Input: "()"
// Output: 1
// Example 2:
//
// Input: "(())"
// Output: 2
// Example 3:
//
// Input: "()()"
// Output: 2
// Example 4:
//
// Input: "(()(()))"
// Output: 6

int scoreOfParentheses(string S) {
    stack<int> stk;
    int ans = 0;
    for(char &c: S){
        if(c == '('){
            stk.push(ans);
            ans = 0;
        }else{
            ans += stk.top() + max(ans,1);
            stk.pop();
        }
    }
    return ans;
}
