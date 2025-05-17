class Solution {
public:
    vector<int> ConstructCumulativeSums(const vector<int>& nums) {
        vector<int> cumulative_sums;
        cumulative_sums.reserve(nums.size());

        for (int num : nums) {
            if (cumulative_sums.empty()) {
                cumulative_sums.push_back(num);
                continue;
            }

            cumulative_sums.push_back(cumulative_sums.back() + num);
        }

        return cumulative_sums;
    }

    int subarraySum(vector<int>& nums, int k) {
        vector<int> cumulative_sums = ConstructCumulativeSums(nums);
        unordered_map<int, int> value_to_count;

        for (const int cumulative_sum : cumulative_sums) {
            ++value_to_count[cumulative_sum];
        }

        int valid_subarray_count = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            int to_find = k;
            if (i > 0) {
                to_find += cumulative_sums[i - 1];
            }
            valid_subarray_count += value_to_count[to_find];
            --value_to_count[cumulative_sums[i]];
        }

        return valid_subarray_count;
    }
};
