## 考えたこと (step1)
葉にたどり着いたら終了したいので，早期リターンできるBFSが良さそう．

depthとnodeのポインタをpairにして持つ方法でよく書くので，前の問題で勉強した，深さごとに管理する方法にする．

この場合別にqueueである必要がないなと思いvectorを使ったが，パフォーマンスを考えるとqueueがよかったなと思った．

## 時間・空間計算量 (step1)
木の中のノード数をnとして，

時間・空間計算量ともにO(n)．

## 考えたこと (step2)
https://github.com/usatie/leetcode/pull/4/files
https://github.com/colorbox/leetcode/pull/36/files
https://github.com/Ryotaro25/leetcode_first60/pull/24/files

next_depth_nodesがちょっと気持ち悪いなと思っていたところ，nodes_in_next_depthというのを見つけた．こっちの方が良さそう．

https://cpprefjp.github.io/reference/utility/unreachable.html

unreachableについては，GCC/Clangで`__builtin_unreachable`が使えるらしい．MSVCは`__assume(0)`．

C++23ではstd::unreachableがある．

https://github.com/usatie/leetcode/pull/4/files#r1943560954

これもいい．型にエイリアスを貼るのは結構汎用性が高そう．

みんなDFSでも解いているみたいなので，やってみる．

```cpp
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        // leaf
        if (!root->left && !root->right) {
            return 1;
        }

        // both non-empty
        if (root->left && root->right) {
            return 1 + min(minDepth(root->left), minDepth(root->right));
        }

        if (root->left) {
            return 1 + minDepth(root->left);
        }

        return 1 + minDepth(root->right);
    }
};
```

なんかスマートじゃない．

条件分岐がパズルになるなあと思い，case switchで書いてみた．

```cpp
class Solution {
    static const int kLeftBit = 0b1;
    static const int kRightBit = 0b10;
public:
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int flag = 0;
        if (root->left) {
            flag |= kLeftBit;
        }
        if (root->right) {
            flag |= kRightBit;
        }

        switch(flag) {
            case kLeftBit:
                return 1 + minDepth(root->left);
            case kRightBit:
                return 1 + minDepth(root->right);
            case kLeftBit | kRightBit:
                return 1 + min(minDepth(root->left), minDepth(root->right));
            default:
                return 1;
        }
    }
};
```

これはちょっと仰々しすぎるか．

https://github.com/colorbox/leetcode/pull/36/files

関数を切り分けて，rootがnullptrの時をINT_MAXにしている．結局leafかどうかの判定は必要だが，のこりの3つの分岐を減らせるみたい．

https://github.com/Ryotaro25/leetcode_first60/pull/24/files

```cpp
if (node->right == nullptr) {
	return minDepth(node->left) + 1;
}
if (node->left == nullptr) {
	return minDepth(node->right) + 1;
}
return min(minDepth(node->left), minDepth(node->right)) + 1;
```

rootで0が返るからこれで十分なのか，確かに．

最初の実装は冗長だが，正しさについて頭を働かせなくてもわかる点はいいのかもしれないと思った．

## 考えたこと (step3)
1分50秒くらいで書けるようになった．
