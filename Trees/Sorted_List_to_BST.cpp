// Given the sorted linked list: [-10,-3,0,5,9],
//
// One possible answer is: [0,-3,9,-10,null,5], which
// represents the following height balanced BST:
//
//       0
//      / \
//    -3   9
//    /   /
//  -10  5


// O(N) extra space
TreeNode* sortedListToBST(ListNode* head) {
        TreeNode *root;
        if(head == NULL) return NULL;
        vector<int> nums;
        ListNode *curr = head;
        while(curr){
            nums.emplace_back(curr->val);
            curr = curr->next;
        }
        root = helper(nums,0,nums.size()-1);
        return root;
    }
    TreeNode *helper(vector<int> &nums,int l,int h){
        if(l > h)
            return NULL;
        int mid = l + (h-l)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = helper(nums,l,mid-1);
        root->right = helper(nums,mid+1,h);
        return root;
    }


// O(1) space
TreeNode *sortedListToBST(ListNode *head)
    {
    	return sortedListToBST( head, NULL );
    }

    TreeNode *sortedListToBST(ListNode *head, ListNode *tail)
    {
    	if( head == tail )
    		return NULL;
    	if( head->next == tail )    //
    	{
    		TreeNode *root = new TreeNode( head->val );
    		return root;
    	}
    	ListNode *mid = head, *temp = head;
    	while( temp != tail && temp->next != tail )    // 寻找中间节点
    	{
    		mid = mid->next;
    		temp = temp->next->next;
    	}
    	TreeNode *root = new TreeNode( mid->val );
    	root->left = sortedListToBST( head, mid );
    	root->right = sortedListToBST( mid->next, tail );
    	return root;
    }
