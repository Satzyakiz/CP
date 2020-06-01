// Given a singly linked list: A0→A1→…→An-1→An, reorder it to:
// A0→An→A1→An-1→A2→An-2→…
// For example: Given 1->2->3->4->5 its reorder is 1->5->2->4->3.
//
// Note: It is recommended do this in-place without altering the nodes' values.
//
// Example:
// Input:
//
// 2
// 3
// 1 2 3
// 4
// 1 7 3 4
//
// Output:
// 1 3 2
// 1 4 7 3


void reorderList(Node* head) {
    // Your code here
    if(!head || !head->next || !head->next->next)
        return;
    Node *head1 = head,*head2 = NULL;
    Node *slow,*fast;
    slow = fast = head;
    fast = fast->next;
    while(fast && fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast->next)
        slow = slow->next;
    head2 = slow->next;
    slow->next = NULL;
    Node *prev = NULL,*temp;
    while(head2){
        temp = head2->next;
        head2->next = prev;
        prev = head2;
        head2 = temp;
    }
    head2 = prev;
    Node *temp2 = head2;
    while(head1 && head2){
        temp = head1->next;
        head1->next = temp2;
        temp2 = head2->next;
        head2->next = temp;
        head1 = temp;
        head2 = temp2;
    }
}
