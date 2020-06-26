// Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
// Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
//
// Input: head = [[3,null],[3,0],[3,null]]
// Output: [[3,null],[3,0],[3,null]]

unordered_map<Node *,Node *> um;
Node* copyRandomList(Node* head) {
    Node *curr = head;
    Node *newHead = NULL,*newTail = NULL, *curr2;
    while(curr){
        if(!newHead){
            newHead = new Node(curr->val);
            newTail = newHead;
            um[curr] = newHead;
        }else{
            newTail->next = new Node(curr->val);
            newTail = newTail->next;
            um[curr] = newTail;
        }
        curr = curr->next;
    }
    curr = head;
    curr2 = newHead;
    while(curr){
        curr2->random = um[curr->random];
        curr = curr->next;
        curr2 = curr2->next;
    }
    return newHead;
}
