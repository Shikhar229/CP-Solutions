class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st(nums.begin(),nums.end());
        int num = k;
        while(st.count(num))num += k;
        return num;    
    }
};