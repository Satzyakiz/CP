
// Input 1:
//     A = "((a + b))"
// Output 1:
//     1
//     Explanation 1:
//         ((a + b)) has redundant braces so answer will be 1.
//
// Input 2:
//     A = "(a + (a + b))"
// Output 2:
//     0
//     Explanation 2:
//         (a + (a + b)) doesn't have have any redundant braces
//         so answer will be 0.

int Solution::braces(string A) {
    stack<char> s;
    int n = A.size();
    int i=0;
    while(i < n){
        char c = A[i];
        if(c == '(' || c == '+' || c == '-' || c == '*' || c == '/')
            s.push(c);
        else if(c == ')'){
            if(s.top() == '(')
                return 1;
            while(!s.empty() && s.top() != '(')
                s.pop();
            s.pop();
        }
        i++;
    }
    return 0;
}
