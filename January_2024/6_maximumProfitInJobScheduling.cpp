class Solution {
public:
    int findNextIdx(vector<vector<int>>& arr, int idx, int currEnd) {
        int start = idx;
        int end = arr.size()-1;
        int result = arr.size();

        while (start <= end) {
            int mid = start + (end-start)/2;

            if (arr[mid][0] >= currEnd) {
                result = mid;
                end = mid-1;
            }
            else {
                start = mid+1;
            }
        }
        return result;
    }
    // int solve(vector<vector<int>>& arr, int idx, vector<int>& dp) {
    //     if (idx >= arr.size()) return 0;
    //     if (dp[idx] != -1) return dp[idx];
    //     int nextIdx = findNextIdx(arr,idx+1,arr[idx][1]);
    //     int take = arr[idx][2] + solve(arr,nextIdx,dp);
    //     int notTake = solve(arr,idx+1,dp);
    //     return dp[idx] = max(take,notTake);
    // }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        vector<vector<int>> arr(n,vector<int>(3,0));

        for (int i=0; i<n; i++) {
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
        }

        sort(begin(arr),end(arr));

        vector<int> dp(n+1,0);

        dp[n] = 0;
        for (int idx=n-1; idx>=0; idx--) {
            int nextIdx = findNextIdx(arr,idx+1,arr[idx][1]);
            int take = arr[idx][2] + dp[nextIdx];
            int notTake = dp[idx+1];
            dp[idx] = max(take,notTake);
        }

        return dp[0];
    }
};
