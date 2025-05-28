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
    bool IsLeaf(TreeNode* node) {
        return !node->left && !node->right;
    }

    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        vector<TreeNode*> same_depth_nodes;
        same_depth_nodes.push_back(root);
        int depth = 1;
        while (!same_depth_nodes.empty()) {
            vector<TreeNode*> next_depth_nodes;
            for (const auto node : same_depth_nodes) {
                if (IsLeaf(node)) {
                    return depth;
                }
                if (node->left) {
                    next_depth_nodes.push_back(node->left);
                }
                if (node->right) {
                    next_depth_nodes.push_back(node->right);
                }
            }
            ++depth;
            same_depth_nodes = move(next_depth_nodes);
        }

        assert(false);
    }
};
