//If there is a intersction, we would definitely get it in 2 traversals.
//Let Linked List 1 have m nodes and Linked List 2 have n nodes.
// 2 traversals for each Linked List = m+n
//i.e. after m+n, both will be pointing to NULL if there is no intersction.

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        ListNode *curr1 = headA, *curr2 = headB;
        int count1 = 0,count2 = 0;
        while(curr1 != curr2){
                if(curr1 == curr2) return curr1;
                curr1 = curr1->next;
                curr2 = curr2->next;
                if(curr1 == NULL) {
                    if(count1++ == 0)
                    //first traversal, so second chance given through the
                    //other head node
                        curr1 = headB;
                    else
                        return NULL;
                }
                if(curr2 == NULL){
                    if(curr2++ == 0)
                    //first traversal, so second chance given through the
                    //other head node
                        curr2 = headA;
                    else
                        return NULL;
                }
        }
        return curr1;
    }
