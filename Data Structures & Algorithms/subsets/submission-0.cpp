class Solution {
public:
    void utility(const vector<int>& nums, vector<int>& tmp, vector<vector<int>>& res, int idx) {
        res.push_back(tmp);
        if (idx == nums.size()) {return;}

        for (int i = idx; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            utility(nums, tmp, res, i + 1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        vector<vector<int>> res;
        utility(nums, tmp, res, 0);
        return res;
    }
};
