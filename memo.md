## 考えたこと (step1)
連結成分のカウント．例のようにDFS，BFSとフラグの配列を用意すれば解けるが，練習もこめてDSUを使う．

ただ，空で書けないので，[ACL](https://github.com/atcoder/ac-library/blob/master/atcoder/dsu.hpp)ものを借りてきてaccepted．

いい加減空で書けるようにならないといけない．

ただ，コピペしてきたのはちょっと機能が多くて大変なので，もうちょっと簡略化したものを書けるように練習する．

## 時間・空間計算量 (step1)
空間計算量はO(n)．

時間計算量はforの中でmergeしているのが一番重くて，O(n α(n))
