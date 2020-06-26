// Example:
//
// Given this linked list: 1->2->3->4->5
//
// For k = 2, you should return: 2->1->4->3->5
//
// For k = 3, you should return: 3->2->1->4->5

ListNode *reverseLL(ListNode *head,int k){
    int i=0;
    ListNode *nextNode = NULL,*temp;
    ListNode *curr = head;
    while(i < k){
        temp = curr->next;
        curr->next = nextNode;
        nextNode = curr;
        curr = temp;
        i++;
    }
    return head = nextNode;
}
ListNode* reverseKGroup(ListNode* head, int k) {
    if(k == 1)
        return head;
    ListNode *curr = head, *nHead = head, *nTail = NULL,*temp;
    int flag = 0;
    while(curr){
        temp = curr;
        for(int i=0; i<k; i++){
            if(!temp){
                flag = 1;
                break;
            }
            temp = temp->next;
        }

        if(flag == 1)
            break;
        if(nHead == head){
            nHead = reverseLL(curr,k);
        }else{
            nTail->next = reverseLL(curr,k);
        }
        curr = nHead;
        while(curr->next != NULL) curr = curr->next;
        nTail = curr;
        curr = temp;
    }
    nTail->next = curr;
    return nHead;
}
