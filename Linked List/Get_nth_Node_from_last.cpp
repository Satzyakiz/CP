// Input:
// 2
// 9 2
// 1 2 3 4 5 6 7 8 9
// 4 5
// 10 5 100 5
// Output:
// 8
// -1

int getNthFromLast(Node *head, int n)
{
       // Your code here
       Node *curr = head, *curr2 = head;
       while(n--){
           if(!curr) return -1;
           curr = curr->next;
       }
       while(curr){
           curr = curr->next;
           curr2 = curr2->next;
       }
       return curr2->data;
}
