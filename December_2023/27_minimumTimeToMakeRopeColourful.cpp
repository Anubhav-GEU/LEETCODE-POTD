class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalTime = 0;
        int n = colors.length();
        int start = 0;
        int end = 0;

        while (start<n && end<n) {
            int groupTotal = 0;
            int maxTime = INT_MIN;
            while (end<n && colors[end] == colors[start]) {
                groupTotal += neededTime[end];
                maxTime = max(maxTime,neededTime[end]);
                end++;
            }
            totalTime += (groupTotal-maxTime);
            start = end;
        }
        return totalTime;
    }
};
