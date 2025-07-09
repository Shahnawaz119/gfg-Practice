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
    bool isLeaf(Node* root){
        return root->left==NULL && root->right==NULL;
    }
    void leafValue(Node* root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        if(isLeaf(root)){
            ans.push_back(root->data);
            return;
        }
        leafValue(root->left,ans);
        leafValue(root->right,ans);
    }
    void leftValue(Node* root,vector<int>&ans){
        while(root!=NULL){
            if(!isLeaf(root)){
                ans.push_back(root->data);
            }
            if(root->left!=NULL){
                root=root->left;
            }else{
                root=root->right;
            }
        }
    }
    void rightValue(Node* root,vector<int>&ans){
        vector<int> temp;
        while(root){
            if(!isLeaf(root)){
                temp.push_back(root->data);
            }
            if(root->right!=NULL){
                root=root->right;
            }else{
                root=root->left;
            }
        }
        reverse(temp.begin(),temp.end());
        ans.insert(ans.end(),temp.begin(),temp.end());
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        if(!isLeaf(root)){
            ans.push_back(root->data);
        }
        leftValue(root->left,ans);
        leafValue(root,ans);
        rightValue(root->right,ans);
        return ans;
    }
};