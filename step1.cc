class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> string_to_number;

        for (string s: strs) {
            string t(s);
            sort(t.begin(), t.end());
            string_to_number[t].push_back(s);
        }

        vector<vector<string>> result_strs;
        for (auto [_, same_strs] : string_to_number) {
            result_strs.push_back(same_strs);
        }

        return result_strs;
    }
};
