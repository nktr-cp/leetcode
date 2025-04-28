## 考えたこと (step1)
nextのポインタを辿って，すでに見たことのあるポインタが登場したなら，循環があることになる．
これはheadがポインタで渡される限り，始点から一つづつ数えて問題ないはず．
見たことのあるポインタの記録は平衡二分木で実装されているstd::setを使えばちょっと効率的なはず．
実装 -> accepted (5分くらい)

## 時間・空間計算量 (step1)
std::setなので要素に重複はないはず．

https://cpprefjp.github.io/reference/set/set/count.html
https://cpprefjp.github.io/reference/set/set/insert.html

上の資料を見るに，countメソッドもinsertメソッドもO(logN)でできるように思えるので，
ノード数をNとして，時間計算量がO(N logN)，空間計算量がO(N)ではないか．

