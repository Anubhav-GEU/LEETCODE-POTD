class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isMonoIncreasing = true;
        bool isMonoDecreasing = true;
        int n = nums.size();

        for (int i=0; i<n-1; i++){
            if (nums[i] > nums[i+1]){
                isMonoIncreasing = false;
                break;
            }
        }
        if (isMonoIncreasing == false){
            for (int i=n-1; i>=1; i--){
                if (nums[i] > nums[i-1]){
                    isMonoDecreasing = false;
                    break;
                }
            }
        }

        return isMonoIncreasing||isMonoDecreasing;
    }
};
