/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        // code here
        if(root==NULL){
            return NULL;
        }
        while(root){
            if(n1->data<root->data && n2->data<root->data){
                root=root->left;
            }else if(n1->data>root->data && n2->data>root->data){
                root=root->right;
            }else{
                break;
            }
        }
        return root;
    }
};