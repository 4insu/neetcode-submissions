class Solution {
public:
    void utility(const vector<int>& nums, vector<int>& tmp, vector<vector<int>>& res, int idx) {
        res.push_back(tmp);
        if (idx == nums.size()) {return;}

        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1]) continue;
            tmp.push_back(nums[i]);
            utility(nums, tmp, res, i + 1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        vector<vector<int>> res;
        utility(nums, tmp, res, 0);
        return res;
    }
};
