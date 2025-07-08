/*
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val)
        : data(val)
        , left(nullptr)
        , right(nullptr) {}
};
*/

class Solution {
  public:
    Node* buildBST(vector<int> &arr,int s,int e){
        if(s>e){
            return NULL;
        }
        int mid=s+(e-s)/2;
        Node* curr=new Node(arr[mid]);
        curr->left=buildBST(arr,s,mid-1);
        curr->right=buildBST(arr,mid+1,e);
        return curr;
    }
    Node* sortedArrayToBST(vector<int>& nums) {
        // Code here
        int n=nums.size();
        
        Node* root=buildBST(nums,0,n-1);
        return root;
    }
};