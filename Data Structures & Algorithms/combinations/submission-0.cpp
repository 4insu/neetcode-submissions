class Solution {
public:
    void utility(int n, vector<int>& tmp, vector<vector<int>>& res, int idx, int k) {
        if (k == 0) {res.push_back(tmp); return;}

        for (int i = idx; i < n + 1; i++) {
            if (i > idx && i == (i - 1)) continue;
            tmp.push_back(i);
            utility(n, tmp, res, i + 1, k - 1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        vector<vector<int>> res;
        utility(n, tmp, res, 1, k);
        return res;
    }
};