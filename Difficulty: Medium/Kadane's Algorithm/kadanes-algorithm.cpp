class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int n=arr.size();
        int maxSum=INT_MIN;
        int currSum=0;
        for(int i=0; i<n; i++){
            currSum+=arr[i];
            maxSum=max(maxSum,currSum);
            if(currSum<0){
                currSum=0;
            }
        }
        return maxSum;
    }
};