
// Input:
// 2
// 5
// 2 2 1 4 4
// 4
// 6
// 1 2 2 3 2 3
// 2
//
// Output:
// 2 2 1
// 1 3 3



Node* deleteAllOccurances(Node *head,int x)
{
    //Your code here

    while(head && head->data == x)
        head = head->next;
    Node *curr = head->next,*prev=head;
    while(curr){
        if(curr->data == x){
            curr = curr->next;
        }else{
            prev->next = curr;
            prev = prev->next;
            curr = curr->next;
        }
    }
    prev->next = NULL;
    return head;
}
