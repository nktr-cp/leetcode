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

## 考えたこと (step2)
[ahayashiさんの記事](https://hayapenguin.com/notes/LeetCode/141/LinkedListCycle)を読んだ．
空間計算量O(1)で実装できるそうなので，やってみる．
```cpp
ListNode* fast, slow;
fast = slow = head;
```
のように初期化して怒られてしまった．
このように初期化するとListNode*型のfastとListNode型のslowになるよう．
C/C++コンパイラのカンマ演算子が使われた際の型のつけられ方については注意するようにする．
これは参照でもいえるらしい．以下chatGPTに書いてもらったコード
```cpp
#include <iostream>
#include <type_traits>

int main() {
    int num = 42;
    int& a = num, b = num;

    std::cout << std::boolalpha;
    std::cout << "a is reference? " << std::is_reference<decltype(a)>::value << std::endl;
    std::cout << "b is reference? " << std::is_reference<decltype(b)>::value << std::endl;
}
```
結果
```bash
a is reference? true
b is reference? false
```

## 時間．空間計算量 (step2)
空間計算量は明らかにO(1)．
時間計算量は，循環がない時はfastがnullptrに到達するまでで，明らかにO(N)．
循環がある時はslowとfastがどちらも循環に入ってしまえば，高々循環の長さ分だけの繰り返しで両者が一致することからO(N)．

