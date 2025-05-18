## 考えたこと (step1)
連結成分を求める問題．

BFSでもDFSでも解けるが，DFSにした．

## 時間・空間計算量 (step1)
時間計算量O(mn)，空間計算量O(1)

## 考えたこと (step2)
https://github.com/colorbox/leetcode/pull/31/files
https://github.com/WNomunomu/leetcode/pull/1/files
https://github.com/irohafternoon/LeetCode/pull/19

dx, dyはコンパイル時に決定可能なのでconstexprを使う．

https://github.com/irohafternoon/LeetCode/pull/19/files#r2040929359

command-query separation知らなかった，意識してみたい．

validかどうかの判定を関数化するのも良さそう．

https://github.com/irohafternoon/LeetCode/pull/19/files#r2041274965

POD分かりたい．

https://en.cppreference.com/w/cpp/language/classes#POD_class

> This means the type is compatible with the types used in the C programming language, that is, can be exchanged with C libraries directly, in its binary form.

Cとバイナリのレベルで互換性があるデータかどうか，と言う話で，PODだとmemcpyなどCライクなバイナリコピーができる．

int[]はPODだが，vectorはPODでない．ポインタはPODだが参照はPODでない．

ふんわりだけど，effective c++の第4項に書いてある．

> このコンストラクター欲しいですかね。暗黙のやつでもいいのではないですか。
何も書かないと POD になりますが、特にこの場合はデメリットはないですか。

これの意味はわかるようになった．PODだと，

https://en.cppreference.com/w/cpp/language/aggregate_initialization

こういうのが使えたりするらしい．

## 考えたこと (step3)
5分くらいで書けるようになった．
