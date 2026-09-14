class Solution {
  public:
    string reverse(const string& S) {
        // code here
        string temp;
        stack<char>st;
        for(char c : S){
            st.push(c);
    
        }
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        return temp;
    }
};