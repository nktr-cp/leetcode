class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        unordered_set<int> nums1_set;
        nums1_set.reserve(nums1.size());
        nums1_set.insert(nums1.begin(), nums1.end());

        unordered_set<int> intersections;
        for (const int n : nums2) {
            if (nums1_set.contains(n)) {
                intersections.insert(n);
            }
        }

        return vector<int>(intersections.begin(), intersections.end());
    }
};
