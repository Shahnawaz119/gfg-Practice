/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    void inorder(Node* root,vector<int> &node){
        if(root==NULL) return;
        inorder(root->left,node);
        node.push_back(root->data);
        inorder(root->right,node);
    }
    void margeSolve(Node* root1,Node* root2,vector<int>&finalNode){
        vector<int> node1;
        vector<int> node2;
        inorder(root1,node1);
        inorder(root2,node2);
        int i=0;
        int j=0;
        while(i<node1.size() && j<node2.size()){
            if(node1[i]<=node2[j]){
                finalNode.push_back(node1[i++]);
            }else{
                finalNode.push_back(node2[j++]);
            }
        }
        while(i<node1.size()){
            finalNode.push_back(node1[i++]);
        }
        while(j<node2.size()){
            finalNode.push_back(node2[j++]);
        }
    }
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int> finalNode;
        margeSolve(root1,root2,finalNode);
        return finalNode;
        
    }
};