class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<pair<int,int>>vec;
        int n= intervals.size();
        
        for(int i = 0;i < n; i++){
            vector<int>a = intervals[i];
            vec.push_back({intervals[i][1], intervals[i][0]});
        }
        sort(vec.begin(),vec.end());
        int cnt = 1;
        int prev_end = vec[0].first;
        
        for(int i = 1;i < n; i++){
            if(vec[i].second >= prev_end){
                cnt++;
                prev_end = vec[i].first;
            }
        }
        return n-cnt;

        
    }
};