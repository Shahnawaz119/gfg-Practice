class Solution {
  public:
    // Function to find unit area of the largest region of 1s.
    void DFS(vector<vector<int>> &grid,int i,int j,int r,int c,int &currArea){
        if(i<0 || j<0 || i>=r || j>=c || grid[i][j]==0){
            return;
        }
        currArea++;
        grid[i][j]=0;
        DFS(grid,i-1,j-1,r,c,currArea);
        DFS(grid,i-1,j,r,c,currArea);
        DFS(grid,i-1,j+1,r,c,currArea);
        DFS(grid,i,j+1,r,c,currArea);
        DFS(grid,i+1,j+1,r,c,currArea);
        DFS(grid,i+1,j,r,c,currArea);
        DFS(grid,i+1,j-1,r,c,currArea);
        DFS(grid,i,j-1,r,c,currArea);
    }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int r=grid.size();
        int c=grid[0].size();
        int ans=0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]==1){
                    int currArea=0;
                    DFS(grid,i,j,r,c,currArea);
                    ans=max(ans,currArea);
                }
            }
        }
        return ans;
    }
};