class Solution {
  public:
    void AllElementSumInSubset(vector<int> &arr,vector<int> &ans,int idx,int currSum){
        if(idx==arr.size()){
            ans.push_back(currSum);
            return;
        }
        AllElementSumInSubset(arr,ans,idx+1,currSum+arr[idx]);
        AllElementSumInSubset(arr,ans,idx+1,currSum);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> ans;
        AllElementSumInSubset(arr,ans,0,0);
        return ans;
    }
};