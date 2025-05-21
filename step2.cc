class Solution {
public:
    bool CanConnect(const string& s1, const string& s2) {
        assert(s1.size() == s2.size());
        int num_different_letters = 0;
        for (size_t i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                ++num_different_letters;
            }
        }

        return num_different_letters == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        const size_t end_word_index = distance(wordList.begin(), find(wordList.begin(), wordList.end(), endWord));
        if (end_word_index == wordList.size()) {
            return 0;
        }

        const size_t num_words = wordList.size();
        vector<vector<int>> adjacency_list(num_words);

        // wordList[i] <-> wordList[j]
        for (size_t i = 0; i < num_words; ++i) {
            for (size_t j = i + 1; j < num_words; ++j) {
                if (CanConnect(wordList[i], wordList[j])) {
                    adjacency_list[i].push_back(j);
                    adjacency_list[j].push_back(i);
                }
            }
        }

        queue<pair<size_t, size_t>> candidates;
        vector<uint8_t> marked(num_words);
        for (size_t i = 0; i < num_words; ++i) {
            if (CanConnect(beginWord, wordList[i])) {
                candidates.emplace(2, i);
                marked[i] = 1;
            }
        }

        while (!candidates.empty()) {
            auto [steps, current_index] = candidates.front();
            candidates.pop();
            if (current_index == end_word_index) {
                return steps;
            }

            for (auto next_index : adjacency_list[current_index]) {
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
