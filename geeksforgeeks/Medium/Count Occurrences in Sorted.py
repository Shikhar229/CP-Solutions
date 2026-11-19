class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int idx = lower_bound(arr.begin(),arr.end(),target)-arr.begin();
        int uidx = upper_bound(arr.begin(),arr.end(),target)-arr.begin();
        return uidx-idx;
        
    }
};
