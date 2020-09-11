// Given a BST and a key K. Insert a new Node with value equal to K into the BST.
//
// Example 1:
//
// Input:
//      2
//    /   \
//   1     3
// K = 4
// Output: 1 2 3 4
// Explanation: After inserting the node 4
// Inorder traversal will be 1 2 3 4.
// Example 2:
//
// Input:
//         2
//       /   \
//      1     3
//              \
//               6
// K = 4
// Output: 1 2 3 4 6
// Explanation: After inserting the node 4
// Inorder traversal of the above tree
// will be 1 2 3 4 6.

Node* insert(Node* root, int key)
{
    // Your code here
    Node *head = root;
    while(1){
        if(root->data == key){
            break;
        }
        else if(root->data < key){
            if(root->right)
                root = root->right;
            else{
                root->right = new Node(key);
                break;
            }
        }else{
            if(root->left)
                root = root->left;
            else{
                root->left = new Node(key);
                break;
            }
        }
    }
    return head;
}
