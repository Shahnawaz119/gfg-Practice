// User function template for C++

class Solution {
  public:
    // Function to find all combinations of elements
    void solve(vector<int> &arr,int tar,vector<int> &temp,vector<vector<int>> &ans,int idx){
       if(tar<0 || idx==arr.size()){
           return;
       } 
       if(tar==0){
           ans.push_back(temp);
           return;
       }
       temp.push_back(arr[idx]);
       solve(arr,tar-arr[idx],temp,ans,idx);
       temp.pop_back();
       solve(arr,tar,temp,ans,idx+1);
       
    }
    // in array arr that sum to target.
    vector<vector<int>> combinationSum(vector<int> &arr, int target) {
        // Your code here
        vector<vector<int>> ans;
        vector<int> temp;
        solve(arr,target,temp,ans,0);
        return ans;
    }
};