// There is a corridor in a Jail which is N units long. Given an array
// A of size N. The ith index of this array is 0 if the light at ith
// position is faulty otherwise it is 1.
//
// All the lights are of specific power B which if is placed at
// position X, it can light the corridor from [ X-B+1, X+B-1].
//
// Initially all lights are off.
//
// Return the minimum number of lights to be turned ON to light the
// whole corridor or -1 if the whole corridor cannot be lighted.

// Input 1:
//
// A = [ 0, 0, 1, 1, 1, 0, 0, 1].
// B = 3
// Input 2:
//
// A = [ 0, 0, 0, 1, 0].
// B = 3
//
//
// Example Output
// Output 1:
//
// 2
// Output 2:
//
// -1

int Solution::solve(vector<int> &a, int b) {

    int ans = 0;
    int n = a.size();
    int lastlight = -1;

    for(int i=0 ; i<a.size() ; i++){
        int j=min(i+b-1, n-1) ;
        while(j>lastlight){
            if(a[j] == 1){
                lastlight = j;
                ans++;
                i = j+b-1;
                j = i;
                break;
            }
            j--;
        }
        if(j < i)
            return -1;
    }
    return ans;
}
