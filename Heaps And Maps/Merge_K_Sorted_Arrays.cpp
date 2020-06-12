//GFG

// Input:
// 2
// 3
// 1 2 3 4 5 6 7 8 9
// 4
// 1 2 3 4 2 2 3 4 5 5 6 6 7 8 9 9
//
// Output:
// 1 2 3 4 5 6 7 8 9
// 1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9

int *mergeKArrays(int arr[][N], int k)
{
//code here
    priority_queue<int> H;
    for(int i=0; i<k; i++){
        for(int j=0; j<k; j++){
            H.push(arr[i][j]);
        }
    }
    int *ans=new int[k*k];
    for(int i=k*k-1; i>= 0; i--){
        ans[i] = H.top();
        H.pop();
    }
    return ans;

} 
