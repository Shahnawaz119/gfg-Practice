class Solution {
  public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        // code here
        vector<int> ans;
        unordered_set<int> s;
        for(int el:a){
            s.insert(el);
        }
        unordered_set<int> s1;
        for(int el:b){
            if(s.find(el)!=s.end()){
                s1.insert(el);
            }
        }
        for(int el:s1){
            ans.push_back(el);
        }
        return ans;
    }
};