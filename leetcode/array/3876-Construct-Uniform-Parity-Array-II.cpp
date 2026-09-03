class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n= nums1.size();
        bool alleven = true;
        bool allodd = true;
        int mini= INT_MAX;
        
        for(int i = 0;i < n ;i++){
            if(nums1[i]%2 == 0) allodd = false;
            else alleven = false;
            mini = min(mini,nums1[i]);

        }
        if(alleven || allodd || mini%2 ==1)return true;
        return false;


    }
};