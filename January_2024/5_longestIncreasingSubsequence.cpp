class Solution {
public:
    int lis(int prev,int curr,vector<int>& arr, vector<vector<int>>& dp){
        if(curr==arr.size()){
            return 0;
        }
        if (dp[curr][prev+1] != -1) return dp[curr][prev+1];
        int first=0;
        if(prev==-1 || arr[prev]<arr[curr]){
            first=1+lis(curr,curr+1,arr,dp);
        }
        int sec=lis(prev,curr+1,arr,dp);
        return dp[curr][prev+1] = max(first,sec);
    }
    // int findWays(vector<int>& nums, int idx, int prev, int& n, vector<vector<int>>& dp) {
    //     if (idx == n) return 0;
    //     // not take
    //     // if (dp[idx][prev+1] != -1) return dp[idx][prev+1];

    //     int len1 = 0;
    //     if (prev == -1 || nums[idx] > nums[prev]) {
    //         len1 = 1+findWays(nums,idx+1,idx,n,dp);
    //     }
    //     int len2 = findWays(nums,idx+1,prev,n,dp);
    //     // take

    //     return max(len1,len2);
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        return lis(-1,0,nums,dp);
        // return len;
    }
};
