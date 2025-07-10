/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    void solve(Node* root,vector<vector<int>> &ans){
        if(root==NULL){
            return;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            Node* curr=q.front();
            temp.push_back(curr->data);
            q.pop();
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
            ans.push_back(temp);
        }
    }
    vector<vector<int>> levelOrder(Node *root) {
        // Your code here
        vector<vector<int>> ans;
        solve(root,ans);
        return ans;
    }
};