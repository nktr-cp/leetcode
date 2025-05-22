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

## 考えたこと (step2)
https://github.com/Ryotaro25/leetcode_first60/pull/23/files
https://github.com/haniwachann/leetcode/pull/4/files
https://github.com/colorbox/leetcode/pull/35/files

https://discord.com/channels/1084280443945353267/1227073733844406343/1236324993839792149

stackのtopへ参照をとって，使い終わったらpop，としている．多少読みにくい気もするが、コピーが重いオブジェクトに対してはよさそう．

```cpp
for (; !depth_and_node.empty(); depth_and_node.pop()) {
	auto& [depth, parent] = depth_and_node.front();
	if (!parent) {
		continue;
	}
	max_depth = max(max_depth, depth);
	depth_and_node.emplace(depth + 1, parent->left);
	depth_and_node.emplace(depth + 1, parent->right);
}
```

こんな感じにすると，popされることが明確でいいだろうか．あんまり見たことがない気はする．

https://github.com/Ryotaro25/leetcode_first60/pull/23/files#r1693992730

```cpp
max_depth = max(max_depth, depth);
```

これは常に更新されるので，いらないという話．BFSなので，後続のdepthの方が狭義で大きくなるのは，それはそうだった．

https://github.com/colorbox/leetcode/pull/35/files#r1914645761

これは確かに．同じ深さのノードはforで同時に処理してしまえば，depthはいらない．

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        queue<TreeNode*> same_level_nodes;
        same_level_nodes.push(root);
        int depth = 0;
        for (; !same_level_nodes.empty(); ++depth) {
            size_t level_size = same_level_nodes.size();
            for (size_t i = 0; i < level_size; ++i) {
                TreeNode* node = same_level_nodes.front();
                same_level_nodes.pop();
                if (node->left) {
                    same_level_nodes.push(node->left);
                }
                if (node->right) {
                    same_level_nodes.push(node->right);
                }
            }
        }

        return depth;
    }
};
```

ただちょっと考えることが増えた気がする．rootのバリデーションなどは入れないと動かなくて，ちょっと頭を使った．
