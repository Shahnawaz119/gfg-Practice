/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*you are required to
complete this function */
class Solution {
  public:
    bool hasPathSum(Node *root, int target) {
        // Your code here
        if(root==NULL){
            return false;
        }
        if(root->left==NULL && root->right==NULL){
            return target==root->data;
        }
        int remainingTarget=target-root->data;
        bool leftAns=hasPathSum(root->left,remainingTarget);
        if(leftAns==true){
            return true;
        }
        bool rightAns=hasPathSum(root->right,remainingTarget);
        if(rightAns==true){
            return true;
        }
        return false;
    }
};