class Solution {
  public:
    int leftBS(vector<int> &arr,int tar){
        int ans=-1;
        int left=0;
        int right=arr.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(arr[mid]==tar){
                ans=mid;
                right=mid-1;
            }else if(tar>arr[mid]){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return ans;
    }
    int rightBS(vector<int> &arr,int tar){
        int ans=-1;
        int left=0;
        int right=arr.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(arr[mid]==tar){
                ans=mid;
                left=mid+1;
            }else if(arr[mid]>tar){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ans;
    }
    int countFreq(vector<int>& arr, int target) {
        // code here
        int left=leftBS(arr,target);
        int right=rightBS(arr,target);
        if(left==-1 && right==-1){
            return 0;
        }
        if(left==-1 && right!=-1){
            return 1;
        }
        return right-left+1;
    }
};
