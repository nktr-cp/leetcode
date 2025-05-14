class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> nums1_set(nums1.begin(), nums1.end());
        set<int> nums2_set(nums2.begin(), nums2.end());

        vector<int> intersections;
        for (const int n : nums1_set) {
            if (nums2_set.contains(n)) {
                intersections.push_back(n);
            }
        }

        return intersections;
    }
};
