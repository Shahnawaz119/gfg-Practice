class Solution {
  public:
    // Function to find the nth catalan number.
    int solve(int n,vector<int> &dp){
        if(n==0 || n==1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans=0;
        for(int i=0; i<n; i++){
            ans+=solve(i,dp)*solve(n-1-i,dp);
        }
        return dp[n]=ans;
    }
    int findCatalan(int n) {
        // code here
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};