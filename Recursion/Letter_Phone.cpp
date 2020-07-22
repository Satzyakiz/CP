// Given a digit string, return all possible letter combinations that
// the number could represent.
// A mapping of digit to letters (just like on the telephone buttons)
// is given below.
// Input: Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

void helper(string &A,string temp,int index,
            unordered_map<char,vector<char>> &um,vector<string> &ans){
    if(index > A.size())
        return;
    if(index == A.size()){
        ans.push_back(temp);
        return;
    }

    for(int i=0; i<um[A[index]].size(); i++){
        char ch = um[A[index]][i];
        temp += ch;
        helper(A,temp,index+1,um,ans);
        temp.pop_back();
    }
}
vector<string> Solution::letterCombinations(string A) {
    unordered_map<char,vector<char>> um;
    um['0'] = {'0'};
    um['1'] = {'1'};
    um['2'] = {'a','b','c'};
    um['3'] = {'d','e','f'};
    um['4'] = {'g','h','i'};
    um['5'] = {'j','k','l'};
    um['6'] = {'m','n','o'};
    um['7'] = {'p','q','r','s'};
    um['8'] = {'t','u','v'};
    um['9'] = {'w','x','y','z'};
    vector<string> ans;
    helper(A,"",0,um,ans);
    return ans;
}
