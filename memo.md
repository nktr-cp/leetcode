## 考えたこと (step1)
高速にレーベンシュタイン距離を計算したりするのか？と思ったが、なんかちょっと解法にならなそう．

問題群を見てしまったのもあって，shortest pathの問題だろうと見当がついた．

グラフは無向グラフ．グラフを作れてしまえば，一点始点のBFSをすれば最短距離はもとまりそう．

一応，ナイーブに二重ループでも間に合いそうな気もするので，やってみる． -> accepted.

簡単なことしかしてないのにやけに時間をかけてしまった．実装力が足りないので，反復練習しないといけない．

## 時間・空間計算量 (step1)
隣接行列の構築がボトルネックで，時間・空間計算量ともにO(word.Length ** 2)．

## 考えたこと (step2)
https://github.com/irohafternoon/LeetCode/pull/22/files
https://github.com/Hurukawa2121/leetcode/pull/20/files
https://github.com/colorbox/leetcode/pull/34/files
https://github.com/Ryotaro25/leetcode_first60/pull/22/files

解法はやはりグラフにして，最短経路なのでBFS，というのが一番メジャーなよう．

```cpp
bool no_begin = std::none_of(wordList.begin(), wordList.end(), [beginWord](string s) {
	return s == beginWord;
});
```

こんなことができるんだ，変数のキャプチャが個別にできるのを初めて知った．

この関数なら参照キャプチャをして，`[&beginWord]`が良さそう． -> 書いてあった．

https://github.com/irohafternoon/LeetCode/pull/22/files#r2051603244

https://www.ibm.com/docs/en/xffbg/121.141?topic=appendix-ascii-ebcdic-character-sets

これ全然知らなかった，こんなとんでも文字セットがあるのか．

> 高速にレーベンシュタイン距離を計算したりするのか？と思ったが、なんかちょっと解法にならなそう．

これ，今回は文字列長が同じなので，ハミング距離の方が適切だった．

実行時間が短く済んでいるコードを見ると，隣接リストを作らずに逐次推移先を計算しているよう．まあこれは別にいいか．
