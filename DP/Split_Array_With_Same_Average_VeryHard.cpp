// In a given integer array A, we must move every element of A to either
// list B or list C. (B and C initially start empty.)
//
// Return true if and only if after such a move, it is possible that
// the average value of B is equal to the average value of C, and B and
// C are both non-empty.
//
// Example :
// Input:
// [1,2,3,4,5,6,7,8]
// Output: true
// Explanation: We can split the array into [1,4,5,8] and [2,3,6,7],
// and both of them have the average of 4.5.

vector<vector<vector<bool>>> dp;
bool isPossible(vector<int> &A, int index, int size, int target){
    if(size == 0)
        return target == 0;
    if(index >= A.size())
        return false;
    if(dp[index][target][size] == false)
        return false;
    if(A[index] <= target){
        if(isPossible(A,index+1,size-1,target - A[index]))
            return true;
    }
    if(isPossible(A,index+1,size,target))
        return true;

    return dp[index][target][size] = false;
}
bool splitArraySameAverage(vector<int>& A) {
    dp.clear();
    sort(A.begin(), A.end());
    int total = 0, n = A.size();
    for(int &x: A) total += x;
    dp.resize(n,vector<vector<bool>> (total+1,vector<bool>(n,true)));
    for(int i=1; i<=n/2; i++){
        if((total *i) % n == 0 && isPossible(A,0,i,(total * i)/n))
            return true;
    }
    return false;
}

//Let sum of 2 subsets be S1 and S2 and sizes be n1 and n2;
// S1/n1 = S2/n2
// => S1 * n2 = S2 * n1
// We know S1+S2 = totalSum => S2 = totalSum - S1
// Similarly => n2 = n - n1, where n = n1 + n2
// Therefore S1 = (totalSum * n1) / n


vector<int> ans1;
vector<vector<vector<bool>>> dp;
bool isPossible(vector<int> &A, int index, int target, int size){
    if(size == 0)
        return target == 0;
    if(index >= A.size())
        return false;
    if(dp[index][target][size] == false)
        return false;
    if(A[index] <= target){
        ans1.push_back(A[index]);
        if(isPossible(A,index+1,target - A[index], size-1))
            return true;
        ans1.pop_back();
    }
    if(isPossible(A,index+1,target,size)){
        return true;
    }

    return dp[index][target][size] = false;
}
vector<vector<int> > Solution::avgset(vector<int> &A) {
    vector<vector<int>> ans;
    sort(A.begin(),A.end());
    ans1.clear();
    dp.clear();
    int total = 0;
    for(int &x: A) total += x;
    int n = A.size();

    bool possible = false;
    for(int i=1; i<n; i++)
        if((total * i) % n == 0)
            possible = true;
    if(!possible)
        return ans;

    dp.resize(n,vector<vector<bool>>(total+1,vector<bool>(n,true)));

    for(int i=1; i<n; i++){
        if((total * i )% n)
            continue;
        int x = (total * i)/n;
        if(isPossible(A,0,x,i)){
            vector<int> ans2;
            int i1 = 0, i2 = 0;
            while(i1 < ans1.size() || i2 < A.size()){
                if(i1 < ans1.size() && ans1[i1] == A[i2]){
                    i1++, i2++;
                    continue;
                }

                ans2.emplace_back(A[i2]);
                i2++;
            }
            while(i2 < A.size()){
                ans2.emplace_back(A[i2++]);
            }
            ans.push_back(ans1);
            ans.push_back(ans2);
            return ans;
        }
    }

    return ans;
}
