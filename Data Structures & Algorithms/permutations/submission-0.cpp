class Solution {
public:
    void utility(vector<int>& nums, vector<vector<int>>& res, int idx) {
        if (idx == nums.size()) {res.push_back(nums); return;}

        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1]) continue;
            swap(nums[i], nums[idx]);
            utility(nums, res, idx + 1);
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        utility(nums, res, 0);
        return res;   
    }
};
