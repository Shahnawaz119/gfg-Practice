class Solution {
  public:
    int n;
    bool canIDistribute(vector<int>&arr,int mid,int k){
        int page=arr[0];
        int count=1;
        for(int i=1; i<n; i++){
            if(page+arr[i]>mid){
                page=arr[i];
                count++;
                if(count>k){
                    return false;
                }
            }else{
                page+=arr[i];
            }
        }
        return count<=k;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        n=arr.size();
        if(k>n){
            return -1;
        }
        int left=*max_element(arr.begin(),arr.end());
        int right=0;
        for(int i=0; i<n; i++){
            right+=arr[i];
        }
        int ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(canIDistribute(arr,mid,k)){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ans;
        
    }
};