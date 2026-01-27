class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int left=0;
        int curr=0;
        int right=arr.size()-1;
        while(curr<=right){
            if(arr[curr]==0){
                swap(arr[curr],arr[left]);
                left++;
                curr++;
            }else if(arr[curr]==1){
                curr++;
            }else if(arr[curr]==2){
                swap(arr[curr],arr[right]);
                right--;
            }
        }
    }
};