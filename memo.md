## 考えたこと (step1)
連結成分のカウント．例のようにDFS，BFSとフラグの配列を用意すれば解けるが，練習もこめてDSUを使う．

ただ，空で書けないので，[ACL](https://github.com/atcoder/ac-library/blob/master/atcoder/dsu.hpp)ものを借りてきてaccepted．

いい加減空で書けるようにならないといけない．

ただ，コピペしてきたのはちょっと機能が多くて大変なので，もうちょっと簡略化したものを書けるように練習する．

## 時間・空間計算量 (step1)
空間計算量はO(n)．

時間計算量はforの中でmergeしているのが一番重くて，O(n α(n))

## 考えたこと (step2)
https://github.com/Hurukawa2121/leetcode/pull/19
https://github.com/colorbox/leetcode/pull/33
https://github.com/Ryotaro25/leetcode_first60/pull/20

情報量がすごい，出てきている話について色々調べてみる．

https://github.com/Ryotaro25/leetcode_first60/pull/20/files#r1685631584

> Return value optimization が多くの場合起きるので最適化されるとは思うが、されないこともあるので、ポインターへの書き込みの方が良い、などの定型的な発言は覚えておくといいでしょう。

vectorを戻り値，なんの気なしにやってしまうので，勉強になる．

https://en.cppreference.com/w/cpp/language/copy_elision

```cpp
Noisy f()
{
    Noisy v = Noisy(); // (until C++17) copy elision initializing v from a temporary;
                       //               the move constructor may be called
                       // (since C++17) "guaranteed copy elision"
    return v; // copy elision ("NRVO") from v to the result object;
              // the move constructor may be called
}
```

明らかに無駄なコピーがある時は，これをムーブしてくれる．C++17以降では原則強制．

gnuのコンパイラだと，-fno-elide-constructorsでこれを抑制．

https://gcc.gnu.org/onlinedocs/gcc-3.3.6/gcc/C_002b_002b-Dialect-Options.html

ポインターへの書き込みの方がよい，というのがよくわからない，単純にvectorを参照渡しするのでいいのではないか？

引数で参照で渡すと，暗に内部ではポインター的な何かを経ているので，のような理解でいいのだろうか．

https://github.com/Ryotaro25/leetcode_first60/pull/20/files#r1688158917

> 参照透明性についても調べるとよいと思います。

https://ja.wikipedia.org/wiki/%E5%8F%82%E7%85%A7%E9%80%8F%E9%81%8E%E6%80%A7

> ある式が参照透過であるとは、その式をその式の値に置き換えてもプログラムの振る舞いが変わらないことを言う

純粋関数型言語は参照透過．Haskellでは参照透過を保ちつつ手続き型的なこともするために，(名前はよくみる)"モナド"というコンセプトがあるみたい．

式を置き換えて良いということは，当然副作用がないということ．

例えば，

```cpp
int add(int a, int b) {
	return a + b;
}

int main() {
	int a = 2, b = 3;
	return add(a, b);
}
```

これは`add(a, b)`のところを，評価結果である`5`に置換しても一切の違いがなく，それゆえ参照透過な関数と言える．

ところで，vectorを非const参照にして渡しても競合状態は起こりそうだけど，どうなんだろう．各スレッドごとにvisitedを作れば競合しないか？

emplace_backはpush_backよりも一般的にパフォーマンスがいいらしい．

https://stackoverflow.com/questions/4303513/push-back-vs-emplace-back

https://en.cppreference.com/w/cpp/container/vector/emplace_back

可変長引数を受け取って，完全転送(perfect forwarding)を行うことで，一時オブジェクトの作成を避けて，in-placeで構築しているらしい．

ChatGPTいわく，std::forward, 可変長テンプレート，placement newの3つで実現されるらしい．

あんまりわかってないような気がする．この辺りのムーブセマンティクスとかRVOとかむずかしい...

DSUは，今回の問題に特化したものを作った．

ACLではメモリの工夫のためにsizeとparentが同じ配列で表現されている．

union by sizeはちょっと面倒なので実装せず，mergeはboolを返すように変更した．

## 考えたこと (step3)
2分半で書けるようになった．

これだけシンプルに書けるDSUで，これだけ高速に動作するのすごい．
