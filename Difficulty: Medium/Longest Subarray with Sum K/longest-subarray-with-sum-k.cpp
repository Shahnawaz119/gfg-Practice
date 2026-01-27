class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        unordered_map<int,int> mp;
        int currLen=0;
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
            if(sum==k){
                currLen=max(currLen,i+1);
            }
            if(mp.find(sum-k)!=mp.end()){
                currLen=max(currLen,i-mp[sum-k]);
            }
            
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
        }
        return currLen;
    }
};