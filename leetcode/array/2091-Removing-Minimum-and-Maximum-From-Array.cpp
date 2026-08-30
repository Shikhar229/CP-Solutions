class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n= nums.size();
        int maxi = max_element(nums.begin(),nums.end())-nums.begin();
        int mini= min_element(nums.begin(),nums.end())-nums.begin();

        int left = min(maxi, mini);
        int right = max(maxi,mini);

        return min({ (n- ((right-left)-1)),right+1,n-left });

    }
};