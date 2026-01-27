class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        multiset<int> window;
        for(int i=0; i<k; i++){
            window.insert(arr[i]);
        }
        vector<int> ans;
        ans.push_back(*window.rbegin());
        int left=0;
        int right=k-1;
        while(right<n-1){
            window.erase(window.find(arr[left]));
            left++;
            right++;
            window.insert(arr[right]);
            ans.push_back(*window.rbegin());
        }
        return ans;
    }
};