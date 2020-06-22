

// Example 1:
//
// Input: tasks = ["A","A","A","B","B","B"], n = 2
// Output: 8
// Explanation:
// A -> B -> idle -> A -> B -> idle -> A -> B
// There is at least 2 units of time between any two same tasks.
// Example 2:
//
// Input: tasks = ["A","A","A","B","B","B"], n = 0
// Output: 6
// Explanation: On this case any permutation of size 6 would work since n = 0.
// ["A","A","A","B","B","B"]
// ["A","B","A","B","A","B"]
// ["B","B","B","A","A","A"]
// ...
// And so on.
// Example 3:
//
// Input: tasks = ["A","B","C","D","E","A","B","C","D","E"], n = 4
// Output: 10

int leastInterval(vector<char>& tasks, int n) {
    if(n == 0)
        return tasks.size();
    vector<int> occ(26,0);
    for(char c: tasks){
        occ[c - 'A']++;
    }
    sort(occ.begin(),occ.end());
    // cout<<occ.back()<<endl;
    int gap = (occ.back()-1) * n, total = gap+occ.back();
    //Since there need not be any gap after last item
    //Total = No of gaps + largest count
    // cout<<gap<<" "<<total<<endl;
    for(int i = occ.size()-2; i>=0; i--){
        if(occ[i] == 0)
            break;
        if(gap >= occ[i]){
            if(occ[i] == occ.back()){
                gap -= (occ[i]-1);
                // If multiple largest counts are there, just increase
                // the total size by 1
                total++;
            }else{
                gap -=occ[i];
            }
        }else{
            //easiest case, if there is lack of gaps, then tasks will
            //complete within the size itself
            return tasks.size();
        }
    }
    return total;
}

//
// The idea is to find a way to arrange these tasks, and use as less idle
// intervals as possible.
//
// By observing a few test cases, we know that it's a lot easier to start from
// the task with the highest frequency of occurrence. Let's say the task is A.
// Then we can put all A tasks into the array, and make sure they are separated
//  by n idle inervals.
// A____A____A____A____A____A
//
// number of A = num(A)            // the number of task A
// gap = (num(A) - 1) x n          // the number of idle intervals
// total length = num(A) + gap     // the total length
// Now we need to replace the idle intervals with other tasks. Similarily,
// we'd better start from tasks with the second highest frequency of occurrence.
// Let's say it's B, then
// a) if num(B) < num(A) && num(B) < gap, we know that the total length will
// not be affected. We simply decrement the gap by num(B).
// AB___AB___AB____A____A____A
// b) if num(B) == num(A) && num(B) < gap, we need to decrement the gap
// by num(B) - 1, and also increment total length by 1.
// AB___AB___AB___AB___AB___AB
// c) If we run out of gap, it is great, because this case is even easier
// to handle. It means we don't need any idle intervals at all. Simply
// return the length of all tasks, and we are done. Why? Let's say We have
// all gaps filled, we have an array like this:
// ABCDABCDABCDABCDABCD
// Now we need to insert task E, we can change the filled gaps a little
// bit, make extra spaces for task E, the number of changed gaps depends
// on how many E we have, then the array looks like:
// ABCD_ABCD_ABCDABCDABCD
// With E inserted:
// ABCDEABCDEABCDABCDABCD
// If E repeats as many times as A, the array will look like:
// ABCDEABCDEABCDEABCDEABCDE
// We can always find a way to arrange them without introducing idle intervals.
