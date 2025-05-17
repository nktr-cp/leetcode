class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sum_count;

        int current_sum = 0;
        ++sum_count[current_sum];

        int valid_subarray_count = 0;
        for (const int n : nums) {
            current_sum += n;

            if (sum_count.contains(current_sum - k)) {
                valid_subarray_count += sum_count[current_sum - k];
            }

            ++sum_count[current_sum];
        }

        return valid_subarray_count;
    }
};
