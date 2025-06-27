class Solution {
  public:
    // Please change the array in-place
    void insertionSort(vector<int>& arr) {
        // code here
        int n=arr.size();
        for(int i=1; i<n; i++){
            int curr=arr[i];
            int prev=i-1;
            while(prev>=0 && arr[prev]>curr){
                swap(arr[prev],arr[prev+1]);
                prev--;
            }
            arr[prev+1]=curr;
        }
    }
};