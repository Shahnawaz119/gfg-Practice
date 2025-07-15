class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& arr) {
        // code here
        int n=arr.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                int temp=arr[i][j];
                arr[i][j]=arr[j][i];
                arr[j][i]=temp;
            }
        }
        for(int k=0; k<n; k++){
            int i=0;
            int j=n-1;
            while(i<j){
                int temp=arr[i][k];
                arr[i][k]=arr[j][k];
                arr[j][k]=temp;
                i++;
                j--;
            }
        }
    }
};
