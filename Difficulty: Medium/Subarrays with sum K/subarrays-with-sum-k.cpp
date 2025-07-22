class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int> m;
        m[0]=1;
        int sum=0;
        int count=0;
        for(int i=0; i<arr.size(); i++){
            sum+=arr[i];
            if(m.count(sum-k)){
                count+=m[sum-k];
            }
            m[sum]++;
        }
        return count++;
    }
    
    
};