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
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int depth = 1;
        for (std::queue<TreeNode*> nodes({root}); !nodes.empty(); ) {
            size_t level_size = nodes.size();

            for (size_t i = 0; i < level_size; ++i) {
                const auto node = nodes.front();
                nodes.pop();

                if (!node->left && !node->right) {
                    return depth;
                }
                auto enqueue_if_not_empty = [&](TreeNode* node) {
                    if (node) {
                        nodes.emplace(node);
                    }
                };

                enqueue_if_not_empty(node->left);
                enqueue_if_not_empty(node->right);
            }
            ++depth;
        }
        __builtin_unreachable();
    }
};
