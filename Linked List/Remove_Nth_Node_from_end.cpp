// Given linked list: 1->2->3->4->5, and n = 2.
//
// After removing the second node from the end,
// the linked list becomes 1->2->3->5.

ListNode *remove(ListNode *head,int n){
  ListNode *curr,*prev;
  curr = prev = head;
  int i = 0;
  while(i<n+1){
    if(curr == NULL)
      return head->next;
    curr = curr->next;
    i++;
  }
  while(curr){
    prev = prev->next;
    curr = curr->next;
  }
  prev->next = prev->next->next;
  return head;
}
