class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> countMap;
        for (int num : nums) {
            countMap[num]++;
        }
        
        int operationsCount = 0;
        for (auto& entry : countMap) {
            int val = entry.second;
            while (val > 0) {
                if (val == 1) {
                    return -1;
                }
                if (val== 4 || val==2) {
                    val -= 2;
                    operationsCount++;
                } 
                else {
                    val -= 3;
                    operationsCount++;
                }
            }
        }
        return operationsCount;
        
    }
};
