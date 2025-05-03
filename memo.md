## 考えたこと (step1)
> Open brackets must be closed in the correct order.

の意味がわからなくて (")("は順序が正しくないからだめだよという話だと思っていた)，最初以下のようなコードを書いたが落とされてしまった．

```cpp
class Solution {
public:
    bool isValid(string s) {
        size_t cnt[3]; // (), {}, [], respectively
        cnt[0] = cnt[1] = cnt[2] = 0;

        const std::string open_brackets = "({[";
        const std::string close_brackets = ")}]";

        for (const char& c: s) {
            for (size_t i = 0; i < 3; ++i) {
                if (c == open_brackets[i]) {
                    ++cnt[i];
                }
                if (c == close_brackets[i]) {
                    if (cnt[i] == 0) {
                        return false;
                    }
                    --cnt[i];
                }
            }
        }

        for (size_t i = 0; i < 3; ++i) {
            if (cnt[i]) {
                return false;
            }
        }

        return true;
    }
};
```

落とされたケースを見ると，`"([)]"`とある．
サンプルを見ると`"([])"`これはOKらしいので，"correct order"に深さの指定がある (つまり，開き括弧の中にある異なる種類の開き括弧は，親となる閉じ括弧の中が閉じる前に閉じないといけない) ことに気づく．

うーん，と思いながら書き直し，5分くらいでaccept．

なんというか，問題をはっきり理解しないまま書き出してしまう癖があるのがまずい．

コーディング面接なら，"What do you mean by 'correct order'?"くらいは聞いてから書かないと，ひどいことになりそう．

一応，[同じようなこと](https://leetcode.com/problems/valid-parentheses/description/comments/1567810/)を考えている人がいた．

これ問題がミスリーディングですかね，どうでしょう．

## 時間・空間計算量 (step1)
時間計算量はO(len(s))．空間計算量もO(len(s)) ("{{{{{{" などのケースが最悪)．

## 考えたこと (step2)
まずパッと思いつくこととして，"({["で条件分岐が3回繰り返されている点．

これは事前にハッシュマップを作ってchar to charの関係を作っておけば簡略化できそう．
`[]`オペレーターでアクセスすると，const変数に対してこのオペレーターは使えないと怒られてしまった (キーが存在する時に要素を追加してしまうので)．

https://stackoverflow.com/questions/13354394/reading-object-from-const-unordered-map

~~コメント集を見ると，異常ケースにも配慮しましょうというのが出てくる．書く分にはassertして変なのを入れられたら即abortが楽な気がするが，ちゃんとしたメッセージをthrowしておく方が利用者視点では便利だと思うので，throwするようにしてみる．~~

mapのatメソッドが例外は投げてくれるので，消した．

std::stringにもcontainsメソッドが実装されているらしい (C++23)．これも使った方が綺麗になりそうなので使ってみる．

https://cpprefjp.github.io/reference/string/basic_string/contains.html

あとは，スタックの変数名には何が積まれるのかを書く方が親切．

https://hayapenguin.com/notes/LeetCode/20/ValidParentheses

以上を踏まえて書き直した．

## 考えたこと (step3)
大体2分くらいで書けるようになった．

そろそろ復習をしないと定着しなさそうなので，(無理のない範囲で)レビュー依頼されたタイミングで一度自分でも解いてからコードを読むのをちょっとやってみようと思う．
