class Solution {
  public:
    int flow(int a, int b){
        if(a*b < 0 && a%b != 0){
            return (a/b)-1;
        }
        return a/b;
    }
    int evaluatePrefix(vector<string>& arr) {
        // code here
        stack<int>st;
        int n= arr.size();
        for(int i = n-1; i>= 0; i--){
            if((isdigit(arr[i][0])) ||((arr[i][0] == '-' && arr[i].size() > 1))){
                st.push(stoi(arr[i]));
            }
            else{
                if(st.size() < 2){
                    return -1;
                    
                }
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                
                if(arr[i]  == "+"){
                    st.push(a+b);
                }
                else if(arr[i] == "-"){
                    st.push(a-b);
                }
                else if(arr[i] == "*"){
                    st.push(a*b);
                }
                else if(arr[i] == "/"){
                    st.push(flow(a,b)); 
                    
                }
                else{
                    st.push(round(pow(a,b)));
                }
            }
        }
        if(st.size() == 1) return st.top();
        return -1;
        
    }
};