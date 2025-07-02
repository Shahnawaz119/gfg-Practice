class Solution {
  public:
    int Sum(int n){
        if(n==1 || n==0){
            return n;
        }
        return n+Sum(n-1);
    }
    int findSum(int n) {
        // code here
        int s=Sum(n);
        return s;
    }
};
