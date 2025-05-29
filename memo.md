## 考えたこと (step1)
ぱっと見は再帰で書くには考えることが多くて複雑そうに見えるので，BFSか．

ただ，BFSは非NULLのノードを左から参照できるだけで，それがどのノードにくっついていたのかの情報を保持するのが難しい．

大量のダミーを用意して，queueに大量にnullを詰めるなどすれば解けそうだが，そもそも最大で深さ2000になる制約をみるとこんなことはしないはず．

もう一度再帰で書く方針を考える．すると，再帰だと自分の子供達がどのような構造になっているかに一切気を配る必要がないことに気づく．

計算量的にやや怪しさを感じたが，高々nullになっている左右のノードに対して再帰呼び出しが行われる程度で，問題ないことがわかる．

素直に実装，acceptされた．

## 時間・空間計算量 (step1)
時間・空間計算量ともにO(n)．

## 考えたこと (step2)
https://github.com/irohafternoon/LeetCode/pull/26/files
https://github.com/colorbox/leetcode/pull/37/files
https://github.com/Ryotaro25/leetcode_first60/pull/25/files

> KSentinelはポインタも中身も変更したくないので、const TreeNode* const　にした

これ知らなかった．`const T*`と`T* const`の違いはよく聞く話な気がするが，`const T* const`もできるのか．

https://github.com/Ryotaro25/leetcode_first60/pull/25/files#r1700000658

https://en.cppreference.com/w/cpp/language/destructor.html

trivial destructorについて勉強した．暗黙に定義されるデストラクタで，PODのための必要条件．

deleteはデストラクタの呼び出し分，Cのfreeよりもたくさん仕事をしていて，それゆえdeleteによる明示的な破棄の必要がある場合はPODでない．

https://github.com/Ryotaro25/leetcode_first60/pull/25/files#r1699998271

これも全然知らなかった...

classは暗黙にprivateが上にくるので，いつもprivateを上にしていたが，

https://google.github.io/styleguide/cppguide.html#Declaration_Order
> A class definition should usually start with a public: section, followed by protected:, then private

とはっきり明記されていた．

みんなこれもBFSで書いているので，ちょっとやりたくないなと思いつつ書いてみる．

持たせるのは，root1, root2に加えて，付け替えをやるために親のポインタがいる．あとは，親のどっちにつけるかで，4要素いるか．

構造体にするのもいい命名が思いつかないので，横着してしまう．

```cpp
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
        if (!root1 && !root2) {
            return nullptr;
        }

        using T = std::tuple<TreeNode*, TreeNode*, TreeNode*, Direction>;
        // parent, root1, root2, direction
        std::queue<T> q;
        TreeNode dummy;
        q.emplace(&dummy, root1, root2, Direction::LEFT);

        while (!q.empty()) {
            const auto [parent, r1, r2, direction] = q.front();
            q.pop();

            if (r1 && r2) {
                TreeNode* new_node = new TreeNode(r1->val + r2->val);
                if (direction == Direction::LEFT) {
                    parent->left = new_node;
                }
                if (direction == Direction::RIGHT) {
                    parent->right = new_node;
                }
                q.emplace(new_node, r1->left, r2->left, Direction::LEFT);
                q.emplace(new_node, r1->right, r2->right, Direction::RIGHT);
                continue;
            }

            if (r1) {
                TreeNode* new_node = new TreeNode(r1->val);
                if (direction == Direction::LEFT) {
                    parent->left = new_node;
                }
                if (direction == Direction::RIGHT) {
                    parent->right = new_node;
                }
                q.emplace(new_node, r1->left, nullptr, Direction::LEFT);
                q.emplace(new_node, r1->right, nullptr, Direction::RIGHT);
                continue;
            }

            if (r2) {
                TreeNode* new_node = new TreeNode(r2->val);
                if (direction == Direction::LEFT) {
                    parent->left = new_node;
                }
                if (direction == Direction::RIGHT) {
                    parent->right = new_node;
                }
                q.emplace(new_node, r2->left, nullptr, Direction::LEFT);
                q.emplace(new_node, r2->right, nullptr, Direction::RIGHT);
                continue;
            }
        }

        return dummy.left;
    }
private:
    enum class Direction {
        LEFT,
        RIGHT,
    };
};
```

あとは，newするしない問題の一貫性の話として，一貫して破壊する方向で行くと，

```cpp
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) {
            return root2;
        }
        if (!root2) {
            return root1;
        }
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};
```

こうすると簡潔は簡潔だなと思った．

スマートではないが，step1.ccを最終コードにしてみる．

## 考えたこと (step3)
1分30秒くらいで書けるようになった．
