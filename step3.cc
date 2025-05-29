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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 && root2) {
            TreeNode* new_node = new TreeNode(root1->val + root2->val);
            new_node->left = mergeTrees(root1->left, root2->left);
            new_node->right = mergeTrees(root1->right, root2->right);
            return new_node;
        }
        if (root1) {
            TreeNode* new_node = new TreeNode(root1->val);
            new_node->left = mergeTrees(root1->left, nullptr);
            new_node->right = mergeTrees(root1->right, nullptr);
            return new_node;
        }
        if (root2) {
            TreeNode* new_node = new TreeNode(root2->val);
            new_node->left = mergeTrees(nullptr, root2->left);
            new_node->right = mergeTrees(nullptr, root2->right);
            return new_node;
        }
        return nullptr;
    }
};
