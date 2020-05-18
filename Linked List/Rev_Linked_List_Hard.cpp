// Reverse a linked list from position m to n. Do it in one-pass.
//
// Note: 1 ≤ m ≤ n ≤ length of list.
//
// Example:
//
// Input: 1->2->3->4->5->NULL, m = 2, n = 4
// Output: 1->4->3->2->5->NULL

ListNode *rev(ListNode *head,int m,int n){
    ListNode *prev = NULL, *temp,*tail=NULL;
    while(m <= n){
        temp = head->next;
        head->next = prev;
        prev = head;
        if(tail == NULL) tail = prev;
        head = temp;
        m++;
    }
    tail->next = head;
    return prev;
}

ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n) return head;
        int i = 1;
        ListNode *curr = head,*prev=NULL,*temp;
        while(i < m-1){
            curr = curr->next;
            i++;
        }
        if(m == 1){
            head = rev(curr,m,n);
        }
        else{
            curr->next = rev(curr->next,m,n);
        }
        return head;
    }
