class Solution {
  public:
    vector<int> diffArray(vector<int>& arr, vector<vector<int>>& opr) {
        // code here
        int n=arr.size();
        vector<int> diff(n+1,0);
        for(auto &op:opr){
            int l=op[0];
            int r=op[1];
            int v=op[2];
            diff[l]+=v;
            if(r+1<n){
                diff[r+1]-=v;
            }
        }
        int curr=0;
        for(int i=0; i<n; i++){
            curr+=diff[i];
            arr[i]+=curr;
        }
        return arr;
        
    }
};