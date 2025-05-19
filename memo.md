## 考えたこと (step1)
200. Number of Islandsとほぼ完全に同じ問題．

上の問題をDFSで解いたので，BFSで書いてみた．DFSで書くなら，4方位の再帰先の返してくる値を足して戻り値にすれば良い．

queueに同じrowとcolumnのペアが積まれる時の処理を書き漏らしていて，WAしてしまった．

```cpp
if (visited[row][column]) {
	continue;
}
```

これがなんでいるのかがちょっと考えないといけなくて，これがパズルになっているのでなんとかしたい．

## 時間・空間計算量 (step1)
時間・空間計算量共にO(nm)．

## 考えたこと (step2)
https://github.com/Ryotaro25/leetcode_first60/pull/19/files
https://github.com/mura0086/arai60/pull/22/files
https://github.com/irohafternoon/LeetCode/pull/20/files
https://github.com/colorbox/leetcode/pull/32
https://github.com/Hurukawa2121/leetcode/pull/18/files

forではなくて，手続きをラムダにして四方位ベタ打ちをしているのをみた．あんまりやったことがないのでやってみる．

std::vector<bool>がまずい理由をちゃんと調べる．

これは他のvector<T>とは別な挙動を示す．

たとえば，

```cpp
std::vector<bool> vb = {true, false, true};
bool* p = &vb[0];
```

こういうのがだめ，なぜなら戻り値がstd::vector<bool>::referenceという参照もどきが返る．これがプロキシオブジェクト．

> Exposes class std::vector<bool>::reference as a method of accessing individual bits. In particular, objects of this class are returned by operator[] by value.

やらかしの例を挙げると，

```cpp
int main() {
  auto f = [&](int x) {
    std::vector<bool> v(10);
    return v[x];
  };

  cout << f(4) << endl;
}
```

これはheap-use-after-freeになる．これはv[x]がvへの参照になっていて，関数呼び出しが終わるとvが破棄されるため．

他のvector<T>と同じようにしたいなら，static_cast<bool>(v[x])が必要で，これをすればUBにならない．

https://en.cppreference.com/w/cpp/container/vector_bool

> Since its representation may be optimized, std::vector<bool> does not necessarily meet all Container or SequenceContainer requirements.

step2ではあえて壊さないようにstd::vector<bool>を使ってみる．

> queueに同じrowとcolumnのペアが積まれる時の処理を書き漏らしていて，WAしてしまった．

これについては，enqueue時にフラグの更新をしてしまえば，同じペアが積まれることがなくなる．

こうするとvisitedという変数名が気になるので，markedとかにしようかな．
(どうでしょう，わかりにくいですか？)
