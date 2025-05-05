## 考えたこと (step1)
addだけで，deleteはないので，top kよりも小さい要素は保持しないでいいことに気づく．

長さをkに保っておけばtopをみるだけで済むので，priority_queueだなとなって，実装．

まず，priority_queueは値が小さい方の要素をtop()メソッドで返してくれると思っていて，書き直し．

駒場の授業で教えてもらったheapは小さい要素がtopにあって深くなるほど値が大きくなっていたので，勘違いしていた．
デフォルトで降順は，覚えておく．

続いて，`1 <= k <= nums.length + 1`を見て，k番目の要素がないという心配はしないでいいのか〜と思って，`assert(top_k_.size() == k)`を挟んでおいたところ，これが落ちてしまった．

1-indexedだからついてる1かな？とか深く考えていながったが，`k <= nums.length + 1`は一回addされてちょうど存在しうる長さになっていた．

これを修正，accept (ここまで11分)．

## 時間・空間計算量 (step1)
時間計算量: 最初のpriority_queueの構築に，O(len(nums) log(len(nums)))かかって (ここはheap sortをしているので)，addクエリをQ回としたときに，O(Q log k)かかる．
従って，O(len(nums) log(len(nums)) + Q log k)が時間計算量．

空間計算量: 最大使用しているところだと，O(len(nums))．この場合O(len(nums))と書くのか，O(k)なのかわからない．そもそもサイズがkを超えたら即popする方が良くて，この方法なら素直にO(k)になる．

## 考えたこと (step2)
まず，既存のヒープのトップと`val`引数との大小関係比較をサボってとりあえずpushすると，コード自体はかなり簡潔になる．

```cpp
int add(int val) {
	top_k_.push(val);

	if (top_k_.size() > k_) {
		assert(top_k_.size() == k_ + 1);
		top_k_.pop();
	}

	return top_k_.top();
}
```

ただ，これはプログラム全体のパフォーマンスに充分効いてくる気がするので，ちょっと憚られるのだが，人のコードを読むとこうしていて，うーん．

https://hayapenguin.com/notes/LeetCode/703/KthLargestElementInAStream

https://github.com/BumbuShoji/Leetcode/pull/9/files

https://github.com/rinost081/LeetCode/pull/9/files

まあ，この問題の制約だと定数倍が気になるようなシビアさではないし，かなり書くのが楽になるので，自分もそうすることにした．

コンパイラ警告が嫌なのでk_はsize_tの方がいいなと思うが，まあ問題のプロトタイプがintになっているので安易にメンバ変数だけsize_tにするのもそれはそれで嫌で，深く考えないことにした．

制約から入ることはないが，`k == 0`を入れると壊れるので，これはコンストラクタの時点でthrowしてしまってもいいかも．

