// Input:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// Output: 1->1->2->3->4->4->5->6

ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        ListNode *temp;
        priority_queue<pair<int,ListNode *>> H;
        for(auto head: lists){
            temp = head;
            while(temp){
                H.push({temp->val,temp});
                temp = temp->next;
            }
        }
        ListNode *nextEle = NULL;
        while(!H.empty()){
            temp = H.top().second;
            H.pop();
            temp->next = nextEle;
            nextEle = temp;

        }
        return temp;
    }
