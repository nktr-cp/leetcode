class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagram_map;

        for (const string& str : strs) {
            string sorted_string(str);
            sort(sorted_string.begin(), sorted_string.end());
            anagram_map[sorted_string].push_back(str);
        }

        vector<vector<string>> anagram_groups;
        anagram_groups.reserve(anagram_map.size());
        for (auto& [_, group] : anagram_map) {
            anagram_groups.push_back(move(group));
        }

        return anagram_groups;
    }
};
