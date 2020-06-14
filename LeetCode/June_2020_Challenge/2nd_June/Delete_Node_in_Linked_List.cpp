// Write a function to delete a node (except the tail) in a singly 
// linked list, given only access to that node.
//
// Input: head = [4,5,1,9], node = 5
// Output: [4,1,9]

void deleteNode(ListNode* node) {
        ListNode *prev = node;
        node = node->next;
        while(node->next){
            swap(prev->val,node->val);
            node = node->next;
            prev = prev->next;
        }
        swap(prev->val,node->val);
        prev->next = NULL;
    }
