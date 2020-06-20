// Given 2 integers A and B and an array of integars C of size N.
//
// Element C[i] represents length of ith board.
//
// You have to paint all N boards [C0, C1, C2, C3 … CN-1].
// There are A painters available and each of them takes B units
// of time to paint 1 unit of board.
//
// Calculate and return minimum time required to paint all boards
// under the constraints that any painter will only paint contiguous
// sections of board.
// Return the ans % 10000003

#define ll long long
#define MOD 10000003
bool isPossible(vector<int> &arr,ll length,int people){
    int p = 1;
    ll sum = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] > length)
            return false;
        if(sum + arr[i] > length){
            p++;
            sum = arr[i];
            if(p > people)
                return false;
        }else{
            sum += arr[i];
        }
    }
    return true;
}
int Solution::paint(int A, int B, vector<int> &C) {

    ll low = 0,high=0;
    for(int i=0; i<C.size(); i++)
        high = (high%MOD + C[i]%MOD)%MOD;

    ll ans = high;

    while(low <= high){
        ll mid = low + (high - low)/2;
        if(isPossible(C,mid,A)){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return (int)((B*ans)%MOD);
}
