class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq;

        for (int i=0; i<n; i++) {
            freq[nums[i]]++;
        }
        int maxRows = 0;

        for (auto& i: freq) {
            maxRows = max(maxRows,i.second);
        }

        vector<vector<int>> ans(maxRows);
        freq.clear();

        for (int i=0; i<n; i++) {
            int row = freq[nums[i]];
            ans[row].push_back(nums[i]);
            freq[nums[i]]++;
        }
        return ans;
    }
};
