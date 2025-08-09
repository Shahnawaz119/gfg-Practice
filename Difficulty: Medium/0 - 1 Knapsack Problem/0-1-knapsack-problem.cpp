class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=wt.size();
        vector<vector<int>> dp(n+1,vector<int>(W+1,0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=W; j++){
                int itemWt=wt[i-1];
                int itemValue=val[i-1];
                if(itemWt>j){
                    dp[i][j]=dp[i-1][j];
                }else{
                    dp[i][j]=max(dp[i-1][j],itemValue+dp[i-1][j-itemWt]);
                }
            }
        }
        return dp[n][W];
    }
};