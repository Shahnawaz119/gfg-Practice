class Solution {
  public:
    int getLPSLength(string &s) {
        // code here
        int n=s.length();
        vector<int> lps(n,0);
        int pre=0;
        int suf=1;
        while(suf<n){
            if(s[pre]==s[suf]){
                lps[suf]=pre+1;
                pre++;
                suf++;
            }else{
                if(pre==0){
                    suf++;
                }else{
                    pre=lps[pre-1];
                }
            }
        }
        return lps[n-1];
    }
};