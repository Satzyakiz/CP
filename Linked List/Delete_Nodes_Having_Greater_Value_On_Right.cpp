// Given a singly linked list, remove all the nodes which have a greater 
// value on its next adjacent element.
//
// Example 1:
//
// Input:
// LinkedList = 12->15->10->11->5->6->2->3
// Output: 15 11 6 3
// Explanation: Since, 12, 10, 5 and 2 are
// the elements which have greater elements
// on their next node. So, after deleting
// them, the linked list would like be 15,
// 11, 6, 3.
// Example 2:
//
// Input:
// LinkedList = 10->20->30->40->50->60
// Output: 60
//
// Example 3:
// INPUT: 1 2 1 3
// OUTPUT: 3


Node *compute(Node *head)
{
    // your code goes here
    if(!head) return NULL;
    head->next = compute(head->next);
    if(head->next && head->next->data > head->data)
        return head->next;
    return head;
}
