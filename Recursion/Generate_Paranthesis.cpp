// Given n pairs of parentheses, write a function to generate all
// combinations of well-formed parentheses.
//
// For example, given n = 3, a solution set is:
//
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

    vector<string> ans;
    void solve(int remaining,string s,int flag){
        if(flag < 0) return;
        if(remaining == 0){
            if(flag == 0)
                ans.emplace_back(s);
            return;
        }
        solve(remaining-1,s+"(",flag+1);
        solve(remaining-1,s+")",flag-1);

    }
    vector<string> generateParenthesis(int n) {
        n = n*2;
        solve(n-1,"(",1);
        return ans;
    }
