// User function Template for C++

class Solution {
  public:
    int solve(vector<vector<int>> &mat,int i,int j,int &maxi,vector<vector<int>> &dp){
        if(i>=mat.size() || j>=mat[0].size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right=solve(mat,i,j+1,maxi,dp);
        int diagonl=solve(mat,i+1,j+1,maxi,dp);
        int left=solve(mat,i+1,j,maxi,dp);
        if(mat[i][j]==1){
            dp[i][j]=1+min(right,min(diagonl,left));
            maxi=max(dp[i][j],maxi);
            return dp[i][j];
        }else{
            dp[i][j]=0;
            return 0;
        }
    }
    int maxSquare(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        int maxi=0;
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                solve(mat,i,j,maxi,dp);
            }
        }
        return maxi;
    }
};