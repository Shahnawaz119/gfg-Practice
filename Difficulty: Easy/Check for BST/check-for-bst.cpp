class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    bool validBST(Node* root,Node* min,Node* max){
        if(root==NULL){
            return true;
        }
        if(min!=NULL && min->data>root->data){
            return false;
        }
        if(max!=NULL && max->data<root->data){
            return false;
        }
        return validBST(root->left,min,root) && validBST(root->right,root,max);
    }
    bool isBST(Node* root) {
        // Your code here
        return validBST(root,NULL,NULL);
    }
};