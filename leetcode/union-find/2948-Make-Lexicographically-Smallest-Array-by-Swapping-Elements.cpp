class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

        // choose two indexes swap it if absolute difference is <= limit

        int n = nums.size();
        vector<pair<int, int>> vec;

        for (int i = 0; i < n; i++) {
            vec.push_back({nums[i], i});
        }
        sort(vec.begin(), vec.end());

        int start = 0;
        int end = 0;

        for (int i = 0; i < n - 1; i++) {
            int curr = vec[i].first;
            int next = vec[i + 1].first;

            if (next - curr <= limit) {
                end = i;

            } else {

                // we calculate ki peechle wale group jo ban chuka hai usme
                // rearrange kar denge chhote numbers ko chhoti position assignn
                // hogi position sort kar denge
                end = i;
                vector<int> pos;
                for (int j = start; j <= end; j++) {
                    pos.push_back(vec[j].second);
                }
                sort(pos.begin(), pos.end());
                for (int j = 0; j < pos.size(); j++) {
                    int idx = pos[j];
                    nums[idx] = vec[start + j].first;
                }

                // here group fails we start new group

                start = i + 1;
                end = i + 1;
            }
        }

        end = n - 1;
        vector<int> pos;
        for (int j = start; j <= end; j++) {
            pos.push_back(vec[j].second);
        }
        sort(pos.begin(), pos.end());
        for (int j = 0; j < pos.size(); j++) {
            int idx = pos[j];
            nums[idx] = vec[start + j].first;
        }
        return nums;
    }
};