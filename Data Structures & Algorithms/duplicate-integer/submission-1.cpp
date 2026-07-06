class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (auto &x : nums) freq[x]++;

        return !(freq.size() == nums.size());
    }
};