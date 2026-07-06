class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq_s, freq_t;

        for (auto &x : s) freq_s[x]++;
        for (auto &x : t) freq_t[x]++;

        return freq_s == freq_t;
    }
};
