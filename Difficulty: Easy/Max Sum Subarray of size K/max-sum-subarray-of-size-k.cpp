class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int sum=0;
        for(int i=0; i<k; i++){
            sum+=arr[i];
        }
        int left=0;
        int right=k-1;
        int ans=sum;
        while(right<n-1){
            sum=sum-arr[left];
            left++,right++;
            sum=sum+arr[right];
            ans=max(ans,sum);
        }
        return ans;
    }
};