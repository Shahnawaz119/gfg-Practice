class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=wt.size();
        int m=W;
        vector<vector<int>> arr(n+1,vector<int> (m+1,0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(wt[i-1]>j){
                    arr[i][j]=arr[i-1][j];
                }else{
                    arr[i][j]=max(arr[i-1][j],val[i-1]+arr[i-1][j-wt[i-1]]);
                }
            }
        }
        return arr[n][m];
    }
};