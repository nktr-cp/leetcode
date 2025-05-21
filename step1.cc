class Solution {
public:
    int CountDifferentLetters(const string& s1, const string& s2) {
        assert(s1.size() == s2.size());
        int num_different_letters = 0;
        for (size_t i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                ++num_different_letters;
            }
        }

        return num_different_letters;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int end_word_index = -1;
        for (size_t i = 0; i < wordList.size(); ++i) {
            if (wordList[i] == endWord) {
                end_word_index = i;
                break;
            }
        }

        if (end_word_index == -1) {
            return 0;
        }

        const size_t num_words = wordList.size();
        vector<vector<int>> adjacency_list(num_words);

        // wordList[i] <-> wordList[j]
        for (size_t i = 0; i < num_words; ++i) {
            for (size_t j = i + 1; j < num_words; ++j) {
                if (CountDifferentLetters(wordList[i], wordList[j]) == 1) {
                    adjacency_list[i].push_back(j);
                    adjacency_list[j].push_back(i);
                }
            }
        }

        queue<pair<int, int>> candidates;
        vector<uint8_t> marked(num_words);
        for (size_t i = 0; i < num_words; ++i) {
            if (CountDifferentLetters(beginWord, wordList[i]) == 1) {
                candidates.emplace(2, i);
                marked[i] = 1;
            }
        }

        while (!candidates.empty()) {
            auto [cost, current_index] = candidates.front();
            candidates.pop();
            if (current_index == end_word_index) {
                return cost;
            }

            for (auto next_index : adjacency_list[current_index]) {
                if (marked[next_index]) {
                    continue;
                }
                candidates.emplace(cost + 1, next_index);
                marked[next_index] = 1;
            }
        }

        return 0;
    }
};
