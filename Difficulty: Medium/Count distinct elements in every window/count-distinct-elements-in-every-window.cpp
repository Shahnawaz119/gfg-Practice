class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        unordered_map<int,int> freq;
        vector<int> ans;
        for(int i=0; i<k; i++){
            freq[arr[i]]++;
        }
        ans.push_back(freq.size());
        for(int i=k; i<n; i++){
            freq[arr[i-k]]--;
            if(freq[arr[i-k]]==0){
                freq.erase(arr[i-k]);
            }
            freq[arr[i]]++;
            ans.push_back(freq.size());
        }
        return ans;
    }
};