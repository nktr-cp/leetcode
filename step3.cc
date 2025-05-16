class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> char_to_count;

        for (const char c : s) {
            ++char_to_count[c];
        }

        for (size_t i = 0; i < s.size(); ++i) {
            if (char_to_count[s[i]] == 1) {
                return static_cast<int>(i);
            }
        }

        return -1;
    }
};
