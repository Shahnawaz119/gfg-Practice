// User function template for C++

class Solution {
  public:
    // Function to find all combinations of elements
    // in array arr that sum to target.
    void solve(vector<int>& arr,int tar,vector<int>&temp,vector<vector<int>>&ans,int idx){
        if(tar==0){
            ans.push_back(temp);
            return;
        }
        if(tar<0 || idx==arr.size()){
            return;
        }
        for(int i=idx; i<arr.size(); i++){
            if(i>idx && arr[i]==arr[i-1]){
                continue;
            }
            temp.push_back(arr[i]);
            solve(arr,tar-arr[i],temp,ans,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> uniqueCombinations(vector<int> &arr, int target) {
        // Your code here
        vector<vector<int>> ans;
        vector<int> temp;
        sort(arr.begin(),arr.end());
        solve(arr,target,temp,ans,0);
        return ans;
    }
};