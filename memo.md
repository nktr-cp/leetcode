## 考えたこと (step1)
子のノードに対しても同じ計算ができれば問題が解けるので，再帰で解きたい．

ベースケースは`!root`にすると場合分けがややこしくなくてよさそう． -> accepted

再帰なしでBFSでも解けるはず．下みたいな感じ．

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // depth, node
        queue<pair<int, TreeNode*>> depth_and_node;

        depth_and_node.emplace(1, root);
        int max_depth = 0;
        while (!depth_and_node.empty()) {
            auto [depth, parent] = depth_and_node.front();
            depth_and_node.pop();
            if (!parent) {
                continue;
            }
            max_depth = max(max_depth, depth);
            depth_and_node.emplace(depth + 1, parent->left);
            depth_and_node.emplace(depth + 1, parent->right);
        }
        return max_depth;
    }
};
```

まあ，これはDFSかという気がする．

## 時間・空間計算量 (step1)
時間・空間計算量ともに，nをノード数として，O(n)．
