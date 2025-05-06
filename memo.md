## 考えたこと (step1)
まず，各数字の登場回数を数えたい．これはhashmapを作って，入力の配列を一回走査すれば簡単にできる．

そうすると，登場回数をfirst，その数自身をsecondにしたpairを作成し，priority_queueに詰めれば，最頻のk個が得られる．

珍しくバグなく書けて，accept (ここまで6分)．

ただ変数名など適当につけているので，そのあたりを以降のステップで改善する．

## 時間・空間計算量 (step1)
時間計算量がO(n logn)，空間計算量がO(n)．

ただし，これは簡単に，時間計算量がO(n logk)，空間計算量がO(k)にできるはずで，次のステップで修正する．

## 考えたこと (step2)
python人気がすごく，cppで解いている人が少ない...

https://github.com/Hurukawa2121/leetcode/pull/9/files
https://github.com/mura0086/arai60/pull/14/files

[構造化束縛](https://cpprefjp.github.io/lang/cpp17/structured_bindings.html)を使っている人が多い．

確かにfirst, secondだと，いつもちょっと考えないとわからなくなるので，こっちの方がわかりやすそう．

また，`[[maybe_unused]]`についても勉強した．

構造化束縛に対して使う場合は，

```cpp
auto [[[maybe_unsed]] _, b] = p
```

みたいなことはできなくて，

```cpp
[[maybe_unused]] auto [_, b] = p
```

とすることになりそう．

あとは，構造体を実装して比較演算子を実装することも推奨されている．

こっちの方が可読性は高いだろうし，実装しなれてもないので，step2はこの方向性で書いてみる．

当たり前だが，priority_queueにgreaterを指定するときには`>`が実装されてないとダメで，lessを使用するときには`<`が定義されてないとダメ．

`<`を実装しておけば，`a > b`がbに対して`<`演算子を呼び出して，`b < a`と書けることを利用して，勝手に`>`を実装してくれたりしないのか？と期待したが，そんなことはなかった．

こういうことがしたいなら，以下のような実装になりそう．

https://cpprefjp.github.io/lang/cpp20/consistent_comparison.html

```cpp
struct Frequency {
    int number;
    int count;

    Frequency(int c, int n): count(c), number(n) {}

    std::strong_ordering operator<=>(const Frequency& other) const {
        return this->count <=> other.count;
    }
};
```

これだけ書いておけば，比較6演算全てが使える．

`std::strong_ordering`は，扱う集合が全順序集合の要件を満たすことを表明するらしい．

https://cpprefjp.github.io/reference/compare/strong_ordering.html

サンプルコードで戻り値の型が後置されていたりして，C++98ばっかり書いてきたせいでもはやC++のコードか判別できないくらい知らない．

https://cpprefjp.github.io/lang/cpp11/trailing_return_types.html

## step3 (考えたこと)
毎回構造体を定義するのが面倒だったので，pairで解いた．

大体2分半くらい．
