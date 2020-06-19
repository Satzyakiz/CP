
// Sort a linked list using insertion sort.
// Input : 1 -> 3 -> 2
// Return 1 -> 2 -> 3

ListNode *insertionSort(ListNode *A){
    if(!A || !A->next)
        return;
    ListNode *dummy = new ListNode(INT_MIN);
    ListNode *temp = A;
    while(temp){
        ListNode *b = dummy;
        while(b->next && b->next->val < A->val)
            b = b->next;
        ListNode *x = temp;
        temp = temp->next;
        x->next = b->next;
        b->next = x;
    }
    return dummy->next;
}
