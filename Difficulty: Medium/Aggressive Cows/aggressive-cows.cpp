class Solution {
  public:
    bool possible(vector<int>&stalls,int mid,int k){
        int currCow=1;
        int currDis=stalls[0];
        for(int i=0; i<stalls.size(); i++){
            if(stalls[i]-currDis>=mid){
                currCow++;
                currDis=stalls[i];
            }
            if(currCow>=k){
                return true;
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(),stalls.end());
        int n=stalls.size();
        int left=0;
        int right=stalls[n-1];
        int ans=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(possible(stalls,mid,k)){
                ans=mid;
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return ans;
    }
};