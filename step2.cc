class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> number_to_index;
        for (int i = 0; i < nums.size(); ++i) {
            if (number_to_index.contains(target - nums[i])) {
                return vector<int>({number_to_index[target - nums[i]], i});
            }
            number_to_index[nums[i]] = i;
        }
        assert(false);
    }
};
