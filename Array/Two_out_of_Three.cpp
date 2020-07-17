// Given are Three arrays A, B and C.
//
// Return the sorted list of numbers that are present in
// atleast 2 out of the 3 arrays.

// Input 1:
//
// A = [1, 1, 2]
// B = [2, 3]
// C = [3]
// Input 2:
//
// A = [1, 2]
// B = [1, 3]
// C = [2, 3]
//
// Output 1:
//
// [2, 3]
// Output 2:
//
// [1, 2, 3]

vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int n1 = A.size(), n2 = B.size(), n3 = C.size();
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(C.begin(),C.end());
    int i=0, j=0, k=0;
    set<int> ans;
    while(i<n1 && j<n2 && k<n3){
        if(A[i] == B[j] && A[i] == C[k]){
            ans.insert(A[i]);
            i++, j++, k++;
        }else if(A[i] == B[j]){
            ans.insert(A[i]);
            i++, j++;
        }else if(A[i] == C[k]){
            ans.insert(A[i]);
            i++, k++;
        }else if(B[j] == C[k]){
            ans.insert(B[j]);
            j++, k++;
        }else{
            if(A[i] < B[j] && A[i] < C[k]){
                i++;
            }else if(B[j] < C[k]){
                j++;
            }else{
                k++;
            }
        }
    }
    while(i<n1 && j<n2 && A[i] == B[j]){
        ans.insert(A[i]);
        i++, j++;
    }
    while(k<n3 && j<n2 && C[k] == B[j]){
        ans.insert(B[j]);
        k++, j++;
    }
    while(i<n1 && k<n3 && A[i] == C[k]){
        ans.insert(A[i]);
        i++, k++;
    }
    vector<int> res(ans.begin(),ans.end());
    return res;
}

//MAP Solution
vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    map<int, set<int>> mp;

    for(int i = 0 ; i < A.size() ; i++){
        mp[A[i]].insert(1);
    }

    for(int i = 0 ; i < A.size() ; i++){
        mp[B[i]].insert(2);
    }

    for(int i = 0 ; i < A.size() ; i++){
        mp[C[i]].insert(3);
    }
    vector<int> ans;

    for(auto it = mp.begin() ; it!=mp.end() ; it++){
        if(it->second.size()>=2){ans.push_back(it->first);}
    }
    return ans;
}
