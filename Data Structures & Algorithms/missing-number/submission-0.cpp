class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sizeNums = nums.size();
        int currSum = 0;
        int totalSum = sizeNums * (sizeNums + 1) / 2;

        for (auto &num : nums) {currSum += num;}

        return totalSum - currSum;
    }
};
