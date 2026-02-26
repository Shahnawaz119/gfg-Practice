class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        int n=start.size();
        if(n==0){
            return 0;
        }
        vector<pair<int,int>> arr;
        for(int i=0; i<n; i++){
            arr.push_back({finish[i],start[i]});
        }
        sort(arr.begin(),arr.end());
        int count=1;
        int lastTime=arr[0].first;
        for(int i=1; i<n; i++){
            if(arr[i].second>lastTime){
                count++;
                lastTime=arr[i].first;
            }
        }
        return count;
    }
};