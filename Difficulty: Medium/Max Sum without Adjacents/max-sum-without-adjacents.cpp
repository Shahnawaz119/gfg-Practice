// User function template for C++
class Solution {
  public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        // code here
        if(arr.size()==0){
            return 0;
        }
        if(arr.size()==1){
            return arr[0];
        }
        vector<int> dp(arr.size());
        dp[0]=arr[0];
        dp[1]=max(arr[0],arr[1]);
        for(int i=2; i<arr.size(); i++){
            dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
        }
        return dp[arr.size()-1];
    }
};