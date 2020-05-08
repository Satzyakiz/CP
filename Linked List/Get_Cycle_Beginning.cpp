// // Given a linked list, return the node where the cycle begins.
// If there is no cycle, return null.
// //
// // To represent a cycle in the given linked list, we use an integer
// pos which represents the position
// // (0-indexed) in the linked list where tail connects to. If pos is -1,
// then there is no cycle in the linked list.

ListNode *detectCycle(ListNode *head) {
       if(head == NULL || head->next == NULL) return NULL;
       ListNode *slow, *fast;
       slow = head;
       fast = head;
       while(fast != NULL && fast->next != NULL){

           slow = slow->next;
           fast = fast->next->next;
           if(slow == fast){
               slow = head;
               while(fast != slow){
                   // cout<<slow->val<<"   "<<fast->val<<endl;
                   slow = slow->next;
                   fast = fast->next;
               }
               return slow;
           }
       }
      return NULL;
}
