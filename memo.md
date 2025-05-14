## 考えたこと (step1)
制約がやけに甘いので，どうやっても解けそう．

とりあえずどちらもsetに変換して，ありうる全要素に対して探索，accepted (2分くらい)．

もっといい書き方はいくらでもあると思うので，step2で検討する．

## 時間・空間計算量 (step1)
n = max(nums1.length, nums2.length)とする．

時間計算量は，セットと要素の検索の両方でO(nlogn)，空間計算量はO(n)．

## 考えたこと (step2)
https://hayapenguin.com/notes/Article/%E7%AB%B6%E6%8A%80%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%9F%E3%83%B3%E3%82%B0/LeetCode/349.+Intersection+of+Two+Arrays
https://github.com/SuperHotDogCat/coding-interview/pull/33/files
https://github.com/Fuminiton/LeetCode/pull/13/files

解法はやはりsetを使ったものが多いが，バリエーションがある．

一つ目に留まったのは，setを構築するのは配列の一方だけにし，もう一方の配列を単純に走査してsetにした配列から二分探索するというもの．この場合は重複を管理するための構造が必要になるものの，n-passは小さくできる．

あとは，配列サイズに関しての問題．ソートをかけるのは小さい方の配列が嬉しいため，swapするというもの．今回は入力が参照で渡されているので少々良くない気もするが，これで書いてみる．

また，この解法では要素の順序についての規則が考慮されていないことに注意しておく．

## 考えたこと (step3)
1分10秒くらいで書けるようになった．
