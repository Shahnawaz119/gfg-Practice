class Solution {
  public:
    bool isPossible(vector<int>&stalls,int mid,int k){
        int cows=1;
        int minVal=stalls[0];
        for(int i=1; i<stalls.size(); i++){
            if(stalls[i]-minVal>=mid){
                cows++;
                minVal=stalls[i];
            }
            if(cows==k){
                return true;
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int n=stalls.size();
        sort(stalls.begin(),stalls.end());
        int left=1;
        int right=stalls[n-1]-stalls[0];
        int ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(isPossible(stalls,mid,k)){
                ans=mid;
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return ans;
    }
};