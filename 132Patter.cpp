class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int third = INT_MIN;
        stack<int> st;
        int n = nums.size();

        for (int i=n-1; i>=0; i--){
            if (nums[i] < third){
                return true;
            }

            while (!st.empty() && st.top() < nums[i]){
                third = st.top();
                st.pop();
            }

            st.push(nums[i]);
        }

        return false;
    }
};
