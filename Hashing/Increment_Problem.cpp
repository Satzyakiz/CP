// Given a stream of numbers A. On arrival of each number, you need to 
// increase its first occurence by 1 and include this in the stream.
//
// Return the final stream of numbers.
//
// Input 1:
//
// A = [1, 1]
// Input 2:
//
// A = [1, 2]
//
// Output 1:
//
// [2, 1]
// Output 2:
//
// [1, 2]

vector<int> Solution::solve(vector<int> &A) {
    unordered_map<int,set<int>> um;
    for(int i=0; i<A.size(); i++){
        um[A[i]].insert(i);
    }

    for(int i=0; i<A.size(); i++){
        int x = A[i];
        if(*(um[x].begin()) == i){

        }else{
            int pos = *(um[x].begin());
            A[pos]++;
            int val = A[pos];
            um[val].insert(pos);
            um[x].erase(pos);
        }
    }
    return A;
}
