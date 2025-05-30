/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }

        size_t nums_length = nums.size();
        TreeNode* root_node = new TreeNode(nums[nums_length / 2]);
        vector<int> former_half = vector<int>(nums.begin(), nums.begin() + nums_length / 2);
        vector<int> latter_half = vector<int>(nums.begin() + nums_length / 2 + 1, nums.end());
        root_node->left = sortedArrayToBST(former_half);
        root_node->right = sortedArrayToBST(latter_half);
        return root_node;
    }
};
