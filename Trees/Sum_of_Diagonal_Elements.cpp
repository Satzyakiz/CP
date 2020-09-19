// Consider Red lines of slope -1 passing between nodes.
//  The diagonal sum in a binary tree is the sum of all node’s data lying
//  between these lines. Given a Binary Tree of size N, print all diagonal sums.
//
// For the following input tree, output should be 9, 19, 42.
// 9 is sum of 1, 3 and 5.
// 19 is sum of 2, 6, 4 and 7.
// 42 is sum of 9, 10, 11 and 12.
//
// Example 1:
//
// Input:
//          4
//        /   \
//       1     3
//            /
//           3
// Output: 7 4
// Example 2:
//
// Input:
//            10
//          /    \
//         8      2
//        / \    /
//       3   5  2
// Output: 12 15 3

vector <int> diagonalSum(Node* root) {
    // Add your code here
    queue<Node *> q;
    q.push(root);
    vector<int> ans;
    while(!q.empty()){
        int k = q.size();
        int sum = 0;
        while(k--){
            Node *temp = q.front();
            q.pop();
            while(temp){
                sum += temp->data;
                if(temp->left) q.push(temp->left);
                temp = temp->right;
            }
        }
        ans.push_back(sum);
    }
    return ans;
}
