class Solution {
  public:
    bool isPossible(vector<int>&arr,int mid,int k){
        int boardSum=0;
        int countPrinter=1;
        for(int i=0; i<arr.size(); i++){
            if(boardSum+arr[i]<=mid){
                boardSum+=arr[i];
            }else{
                boardSum=arr[i];
                countPrinter++;
                if(countPrinter>k){
                    return false;
                }
            }
        }
        return true;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int left=*max_element(arr.begin(),arr.end());
        int right=0;
        int ans=-1;
        for(int i=0; i<n; i++){
            right+=arr[i];
        }
        
        while(left<=right){
            int mid=left+(right-left)/2;
            if(isPossible(arr,mid,k)){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ans;
    }
};