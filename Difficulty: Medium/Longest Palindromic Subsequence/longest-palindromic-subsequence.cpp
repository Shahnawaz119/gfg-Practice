// User function Template for C++

class Solution {
  public:
    int longestPalinSubseq(string &s2) {
        // code here
        string s1=s2;
        reverse(s2.begin(),s2.end());
        int n=s1.size()+1;
        vector<vector<int>> arr(n,vector<int> (n,0));
        for(int i=1; i<n; i++){
            for(int j=1; j<n; j++){
                if(s1[i-1]==s2[j-1]){
                    arr[i][j]=arr[i-1][j-1]+1;
                }else{
                    arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
                }
            }
        }
        return arr[n-1][n-1];
    }
};