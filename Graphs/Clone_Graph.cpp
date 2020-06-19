// Given a reference of a node in a connected undirected graph.
// class Node {
//     public int val;
//     public List<Node> neighbors;
// }

class Solution {
public:
    unordered_map<Node *,Node *> um;
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return NULL;
        if(um.find(node) != um.end())
            return um[node];
        Node *root = new Node(node->val);
        um[node] = root;
        for(auto n : node->neighbors){
            if(um.find(n) != um.end()){
                root->neighbors.push_back(um[n]);
            }
            else{
                Node *child = cloneGraph(n);
                root->neighbors.push_back(child);
            }
        }
        return root;
    }
};

//Explanation
// The problem of the statement is a little confusing. 
// Actually the target here is to replicate a graph, exactly like it is.
//
// The representation of the graph is adjacency list, i.e.
// if node 1 is connected to node 2 and node 3, then [2,3]
// is the representation, which is present in index 1.
//
// In the code, we use an unordered map, which maps a Node *
// to another Node , to store the newly created node that is
// equivalent to an existing node. We use this map so that same
// child is not created multiple times. Once the new version of
// an existing node is created, we just call it from the map.
// As a result the same version of node is called everytime to
// its connected nodes.
//
// If a node is not created, we simply create it, and store it in the map.
// And call it as per our requirement.
//
// If a node from the neighbour is not yet created, we create that neighbor,
// by doing a recursive call to cloneGraph() method and then store it in
// the neighbor of the new version of node that is created
// (else part in the code).
