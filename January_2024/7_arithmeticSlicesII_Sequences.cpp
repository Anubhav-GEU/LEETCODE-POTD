class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        unordered_map<long,int> arr[n];

        for (int i=0; i<n; i++) {
            for (int j=0; j<i; j++) {
                long diff = (long)nums[i] - nums[j];

                auto it = arr[j].find(diff);

                int countAtJ = (it == arr[j].end()) ? 0 : it->second;

                arr[i][diff] += countAtJ+1;
                result += countAtJ;
            }
        }
        return result;
    }
};
