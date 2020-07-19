// Given a linked list A of length N and an integer B.
// You need to reverse every alternate B nodes in the linked list A.
// Input 1:
//  A = 3 -> 4 -> 7 -> 5 -> 6 -> 6 -> 15 -> 61 -> 16
//  B = 3
// Input 2:
//  A = 1 -> 4 -> 6 -> 6 -> 4 -> 10
//  B = 2
//
// Example Output
// Output 1:
//  7 -> 4 -> 3 -> 5 -> 6 -> 6 -> 16 -> 61 -> 15
// Output 2:
//  4 -> 1 -> 6 -> 6 -> 10 -> 4

ListNode* Solution::solve(ListNode* A, int B) {
    int flag = 1;
    vector<ListNode *> v;
    ListNode *curr = A;
    while(curr){
        v.push_back(curr);
        curr = curr->next;
    }
    for(int i=0; i<v.size(); i+= 2*B){
        reverse(v.begin()+i,v.begin()+i+B);
    }
    A = curr = v[0];
    for(int i=1; i<v.size(); i++){
        curr->next = v[i];
        curr = curr->next;
    }
    curr->next = NULL;
    return A;
}
