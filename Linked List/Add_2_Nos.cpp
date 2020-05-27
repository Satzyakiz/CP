// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(),*curr = head;
        int carry = 0,val;
        while(l1 && l2){
            val = l1->val + l2->val + carry;
            carry = val / 10;
            val = val%10;
            curr->val = val;
            l1 = l1->next;
            l2 = l2->next;
            if(l1 && l2)
                curr->next = new ListNode();
            else
                break;
            curr = curr->next;
        }
        if(l1 || l2){
            curr->next = new ListNode();
            curr = curr->next;
        }
        while(l1){
            val = l1->val+carry;
            carry = val / 10;
            val = val%10;
            curr->val = val;
            l1 = l1->next;
            if(l1)
                curr->next = new ListNode();
            else
                break;
            curr = curr->next;
        }
        while(l2){
            val = l2->val+carry;
            carry = val / 10;
            val = val%10;
            curr->val = val;
            l2 = l2->next;
            if(l2)
                curr->next = new ListNode();
            else
                break;
            curr = curr->next;
        }
        if(carry)
            curr->next = new ListNode(1);

        return head;
    }

//Alternative
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;               // digit sum and carry
        ListNode * res = nullptr;  // result to return
        ListNode ** l3 = &res;     // pointer to current list node pointer
        while (true) {
            if (!l1 && !l2 && !sum) {
                break;             // no more digits and carry => we're done!
            }
            if (l1) {              // we have digit from addendum1
                sum += l1->val;    // add it to carry
                l1 = l1->next;     // proceed to the next digit of addendum1
            }
            if (l2) {              // we have digit from addendum2
                sum += l2->val;    // add it to carry
                l2 = l2->next;     // proceed to the next digit of addendum2
            }
            *l3 = new ListNode(sum % 10); // create current result digit node
            l3 = &((*l3)->next);          // proceed to the next result digit
            sum /= 10;                    // carry
        }
        return res;
    } 
