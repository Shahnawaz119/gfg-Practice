// User function template for C++

class Solution {
  public:
    // Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string &s1, string &s2) {
        // code here
        int n=s1.size()+1;
        int m=s2.size()+1;
        vector<vector<int>> arr(n,vector<int>(m,0));
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(s1[i-1]==s2[j-1]){
                    arr[i][j]=arr[i-1][j-1]+1;
                }else{
                    arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
                }
            }
        }
        return n-1+m-1-arr[n-1][m-1];
    }
};