class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        multiset<int> sorted_nums(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            if (sorted_nums.contains(target - nums[i])) {
                if (nums[i] * 2 == target && sorted_nums.count(nums[i]) == 1) {
                    continue;
                }

                int pair_index = std::find(nums.begin() + i + 1, nums.end(), target - nums[i]) - nums.begin();

                return vector<int>({i, pair_index});
            }
        }

        assert(false);
        return vector<int>();
    }
};
