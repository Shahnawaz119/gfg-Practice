
class Solution {
  public:
    int maxLength(string& s) {
        // code here
        stack<int> st;
        st.push(-1);
        int maxLength=0;
        for(int i=0; i<s.length(); i++){
            char ch=s[i];
            if(ch=='('){
                st.push(i);
            }else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    maxLength=max(maxLength,i-st.top());
                }
            }
        }
        return maxLength;
    }
};