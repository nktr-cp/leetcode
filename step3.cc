class Solution {
public:
    bool CanConnect(const string& s1, const string& s2) {
        size_t num_different_letters = 0;
        for (size_t i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                ++num_different_letters;
            }
        }

        return num_different_letters == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        const size_t num_words = wordList.size();
        const size_t end_word_index = distance(wordList.begin(), find(wordList.begin(), wordList.end(), endWord));
        if (end_word_index == num_words) {
            return 0;
        }

        vector<vector<int>> adjacent_list(num_words);
        // steps, index
        queue<pair<size_t, size_t>> candidates;
        vector<uint8_t> marked(num_words);
        for (size_t i = 0; i < num_words; ++i) {
            if (CanConnect(beginWord, wordList[i])) {
                candidates.emplace(2, i);
                marked[i] = 1;
            }
            for (size_t j = i + 1; j < num_words; ++j) {
                if (CanConnect(wordList[i], wordList[j])) {
                    adjacent_list[i].push_back(j);
                    adjacent_list[j].push_back(i);
                }
            }
        }

        while (!candidates.empty()) {
            auto [steps, current_index] = candidates.front();
            candidates.pop();

            if (current_index == end_word_index) {
                return steps;
            }

            for (int next_index : adjacent_list[current_index]) {
                if (marked[next_index]) {
                    continue;
                }
                candidates.emplace(steps + 1, next_index);
                marked[next_index] = 1;
            }
        }

        return 0;
    }
};
