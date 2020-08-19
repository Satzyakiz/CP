
// Return all non-negative integers of length N such that the absolute
// difference between every two consecutive digits is K.
//
// Note that every number in the answer must not have leading zeros except
// for the number 0 itself. For example, 01 has one leading zero and is
// invalid, but 0 is valid.
//
// You may return the answer in any order.

// Example 1:
//
// Input: N = 3, K = 7
// Output: [181,292,707,818,929]
// Explanation: Note that 070 is not a valid number, because it has leading zeroes.
// Example 2:
//
// Input: N = 2, K = 1
// Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]

// Recursive Solution using loops:

    vector<int> ans;
    void helper(int size, int &targetSize, int &K, int no){
        if(size > targetSize)
            return;
        if(size == targetSize){
            ans.push_back(no);
            return;
        }
        if(size == 0){
            for(int i=0; i<=9; i++){
                helper(1, targetSize, K, i);
            }
        }else{
            int x = no % 10;
            for(int i=0; i<=9; i++){
                if(abs(x-i) == K && ((size > 1) || (size == 1 && x != 0))){
                    helper(size+1, targetSize, K, no * 10 + i);
                }
            }
        }
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        ans.clear();
        helper(0,N,K,0);
        return ans;
    }

// Better Solution:

    vector<int> ans;
    void helper(int no, int N, int K){
        if(N == 1){
            ans.push_back(no);
            return;
        }
        int lastDigit = no % 10;
        if(lastDigit - K >= 0){
            helper(no * 10 + (lastDigit - K), N-1, K);
        }
        if(K != 0){
            if(lastDigit + K < 10){
                helper(no * 10 + (lastDigit + K), N-1, K);
            }
        }
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        if(N == 1)
            return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        for(int i = 1; i <= 9; i++){
            helper(i,N,K);
        }
        return ans;
    }
