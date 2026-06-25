class Solution {
  public:
    int floorDiv(int a,int b){
        int res=a/b;
        if((a^b)<0 && a%b!=0){
            res--;
        }
        return res;
    }
    int evaluatePrefix(vector<string>& arr) {
        // code here
        int n=arr.size();
        int num=0;
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            string token=arr[i];
            if(token=="+" || token=="-" || token=="/" || token=="*" || token=="^"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                
                if(token=="+"){
                    st.push(a+b);
                }else if(token=="-"){
                    st.push(a-b);
                }else if(token=="/"){
                    st.push(floorDiv(a,b));
                }else if(token=="*"){
                    st.push(a*b);
                }else if(token=="^"){
                    int ans=pow(a,b);
                    st.push(ans);
                }
            }else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};