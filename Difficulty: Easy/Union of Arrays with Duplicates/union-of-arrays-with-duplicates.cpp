class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        vector<int> ans;
        unordered_set<int> s;
        for(int el:a){
            s.insert(el);
        }
        for(int el:b){
            s.insert(el);
        }
        for(int el:s){
            ans.push_back(el);
        }
        return ans;
    }
};