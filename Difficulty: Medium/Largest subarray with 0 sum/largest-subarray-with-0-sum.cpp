class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        unordered_map<int,int> m;
        int ans=0;
        int sum=0;
        for(int i=0; i<arr.size(); i++){
            sum+=arr[i];
            if(sum==0){
                ans=max(ans,i+1);
            }
            if(m.count(sum)){
                int currLen=i-m[sum];
                ans=max(currLen,ans);
            }else{
                m[sum]=i;
            }
        }
        return ans;
    }
};