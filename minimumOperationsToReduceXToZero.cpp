class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int operations = INT_MAX;

        int n = nums.size();
        int sum = 0;
        for (int i=0; i<n; i++){
            sum += nums[i];
        }

        sum = sum-x;
        if (sum < 0) return -1;

        int curr = 0;

        int low = 0;
        
        for (int right = 0; right<n; right++){
            curr += nums[right];
            while (curr > sum){
                curr -= nums[low];
                low++;
            }

            if (curr == sum){
                operations = min(operations,n - (right-low+1));
            }
        }
        if (operations == INT_MAX) return -1;
        else return operations; 
        
    }
};
