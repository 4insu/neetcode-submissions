class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int singleNum = 0;
        for (auto &num : nums) {singleNum = singleNum ^ num;}

        return singleNum;
    }
};
