// In a party of N people, only one person is known 
// to everyone. Such a person may be present in the party,
// if yes, (s)he doesn’t know anyone in the party. We can only
// ask questions like “does A know B? “. Find the stranger
// (celebrity) in the minimum number of questions.
int getId(int M[MAX][MAX], int n)
{
    unordered_map<int,int> um;
    int celeb = -1;
    for(int i=0; i<n; i++){
        int flag = 1;
        for(int j =0; j<n; j++){
            if(M[i][j]){
                um[j]++;
                flag = 0;
            }
        }
        if(flag){
            celeb = i;
        }
    }
    if(um[celeb] == n-1) return celeb;
    else return -1;
}

//The above function returns the celebrity

// Input:
// MATRIX = { {0, 0, 1, 0},
//            {0, 0, 1, 0},
//            {0, 0, 0, 0},
//            {0, 0, 1, 0} }
// Output:id = 2
// Explanation: The person with ID 2 does not
// know anyone but everyone knows him
//
// Input:
// MATRIX = { {0, 0, 1, 0},
//            {0, 0, 1, 0},
//            {0, 1, 0, 0},
//            {0, 0, 1, 0} }
// Output: No celebrity
// Explanation: There is no celebrity.
