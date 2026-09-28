class Solution {
public:
    void utility(const vector<int>& nums, vector<int>& tmp, vector<vector<int>>& res, int idx, int sum, int target) {
        if (sum == target) {res.push_back(tmp); return;}
        if (sum > target || idx == nums.size()) {return;}

        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1]) continue;
            tmp.push_back(nums[i]);
            utility(nums, tmp, res, i, sum + nums[i], target);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> tmp;
        vector<vector<int>> res;
        utility(nums, tmp, res, 0, 0, target);
        return res;
    }
};
