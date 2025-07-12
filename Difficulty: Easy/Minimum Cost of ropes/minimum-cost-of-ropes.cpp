class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq(arr.begin(),arr.end());
            
        int cost=0;
        while(pq.size()>1){
            int min1=pq.top();
            pq.pop();
            int min2=pq.top();
            pq.pop();
            int currCost=min1+min2;
            cost+=currCost;
            pq.push(currCost);
        }
        return cost;
        
    }
};