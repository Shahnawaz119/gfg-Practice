// User function Template for C++

class Solution {
  public:
    // Function to check if we can reach the last index from 0th index.
    bool canReach(vector<int> &arr) {
        // code here
        int reach=0;
        int n=arr.size();
        for(int i=0; i<=reach; i++){
            reach=max(reach,i+arr[i]);
            if(reach>=n-1){
                return true;
            }
        }
        return false;
    }
};