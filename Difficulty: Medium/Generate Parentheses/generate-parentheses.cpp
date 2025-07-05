// User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution {
  public:
    void solve(int n,vector<string> &ans,int op,int cl,string str){
        if(str.length()==n){
            ans.push_back(str);
            return;
        }
        if(op<n/2){
            solve(n,ans,op+1,cl,str+'(');
        }
        if(cl<op){
            solve(n,ans,op,cl+1,str+')');
        }
    }
    vector<string> generateParentheses(int n) {
        // code here
        vector<string> ans;
        solve(n,ans,0,0,"");
        return ans;
    }
};