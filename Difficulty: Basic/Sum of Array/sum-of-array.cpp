// User function template for C++
class Solution {
  public:
    // Function to return sum of elements
    int Sum(vector<int> &arr,int n){
        if(n<0){
            return 0;
        }
        return arr[n]+Sum(arr,n-1);
    }
    int arraySum(vector<int>& arr) {
        // code here
        int n=arr.size();
        return Sum(arr,n-1);
        
    }
    
};