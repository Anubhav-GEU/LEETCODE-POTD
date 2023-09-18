class Solution {
public:
    int findOne(vector<int>& mat){
        int start = 0;
        int end = mat.size()-1;
        int mid;
        int ans = -1;
        while (start <= end){
            mid = start + (end-start)/2;

            if (mat[mid] == 1){
                ans = mid;
                start = mid + 1;
            }
            else{
                end = mid-1;
            }

        }
        return ans;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;


        int n = mat.size();

        for (int i=0; i<n; i++){
            int count = findOne(mat[i]);
            pq.push({count,i});
        }
        for (int i=0; i<k; i++){
            auto it = pq.top();
            pq.pop();

            ans.push_back(it.second);
        }
        return ans;
    }
};
