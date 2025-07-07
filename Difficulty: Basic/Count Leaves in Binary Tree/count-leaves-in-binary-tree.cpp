/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// Class Solution
class Solution {
  public:
    // Function to count the number of leaf nodes in a binary tree.
    void count(Node* root,int &ans){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            ans++;
            return;
        }
        count(root->left,ans);
        count(root->right,ans);
    }
    int countLeaves(Node* root) {
        // write code here
        int ans=0;
        count(root,ans);
        return ans;
    }
};