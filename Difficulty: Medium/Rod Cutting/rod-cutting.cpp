// User function Template for C++

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        int rodLength=n;
        vector<int> length(n);
        for(int i=0; i<n; i++){
            length[i]=i+1;
        }
        vector<vector<int>> dp(n+1,vector<int>(rodLength+1,0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=rodLength; j++){
                if(length[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }else{
                    dp[i][j]=max(price[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
                }
            }
        }
        return dp[n][rodLength];
    }
};