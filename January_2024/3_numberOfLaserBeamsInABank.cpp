class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prevCount = 0;
        int m = bank.size();
        int n = bank[0].size();
        for (int i=0; i<n; i++) {
            if (bank[0][i] == '1') {
                prevCount++;
            }
        }
        int ans = 0;

        for (int i=1; i<m; i++) {
            int runningCount = 0;

            for (int j=0; j<n; j++) {
                if (bank[i][j] == '1') runningCount++;
            }
            if (runningCount != 0) {
                ans += (runningCount*prevCount);
                prevCount = runningCount;
            }
        }
        return ans;
    }
};
