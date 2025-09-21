class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // code here
        auto myComp=[](int &a1,int &a2){
            string s1=to_string(a1);
            string s2=to_string(a2);
            if(s1+s2>s2+s1){
                return true;
            }
            return false;
        };
        sort(arr.begin(),arr.end(),myComp);
        string result="";
        if(arr[0]==0){
            return "0";
        }
        for(auto &s: arr){
            result+=to_string(s);
        }
        return result;
    }
};