class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        vector<int>freq(128,0);
        for(char  c : s){
            freq[c]++;
        }
        
        vector<vector<char>>bucket(n+1);


        for(int i = 0; i < 128 ; i++){
            if(freq[i] > 0){
                bucket[freq[i]].push_back(char(i));
            }
        }
        string ans = "";
        for(int i = n; i >=1 ; i--){
            for(char  c  :bucket[i]){
                ans.append(i,c);
            }
        }
        return ans;
        
    }
};