class Solution {
  public:
    int MCM(vector<int> &arr,int i,int j,vector<vector<int>> &dp){
        if(i==j){
            return 0;
        }
        int ans=INT_MAX;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        for(int k=i; k<j; k++){
            int cost1=MCM(arr,i,k,dp);
            int cost2=MCM(arr,k+1,j,dp);
            int currCost=cost1+cost2+(arr[i-1]*arr[k]*arr[j]);
            ans=min(currCost,ans);
        }
        return dp[i][j]=ans;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return MCM(arr,1,n-1,dp);
        
    }
};