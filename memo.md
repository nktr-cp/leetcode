## 考えたこと (step1)
~~もっともナイーブに実装すると，各要素について選ぶ選ばないの2^{nums.length}通りある．~~

~~この類はDPしそうだけど，ちょっとどう構成したらいいかわからない．絶対に典型問題な香りがするのだけど...~~

~~同じ数字は区別されないことに注意．各数字を達成する通りの数が分かればよい．~~

~~なんとなく，配列を前から拡張していけば良さげなDPがかけそう．~~

~~k=0の時，空の配列は答えなのか？ -> non-emptyなので，答えじゃない．~~

~~i番目までの要素を使って作れる集合のテーブルをDPテーブルにすればよい，ちょっと計算量的に大丈夫かわからないが実装してみる．~~

~~まずそう．テーブルにする過程で，a+b=cが存在し，新たにbが入ってきた時に，aと足してcを構成してはいけないが，これの判定ができてない (例: [1,1,1]などで，1+1がすでにあるのに最後の1で1+1を作ってしまう)．~~

~~そもそもカリカリに枝狩りしても時間がまずそう，方針を変えたい．~~

contiguousを読んでなかった，上の考察は全く意味がなかったことに気づく．上の問題NP完全なんじゃないか？

NP完全だった...[Subset sum problem](https://en.wikipedia.org/wiki/Subset_sum_problem)というものらしい，頭が悪すぎる．

累積和はとりあえず使えそう．左端を固定して右端を探索する感じ．ただ，負数が入っていて単調性が安易にいえないのが辛く，二分探索ができないので計算量が厳しい．これでは実質2重ループで全ての左右を比べることになってしまう．

累積和の値の個数を事前にマップで構築しておき，エントリを要素を進めるごとに削除していけば，検索のコストがハッシュの問い合わせ1回で済むようになる，これで解けそう． -> accepted

あまり解法に馴染みがなかったこともあり，コードは相当パズルになってしまった．他の人がどのようにして解いているか気になる．

## 時間・空間計算量 (step1)
時間・空間計算量共にO(N)．

## 考えたこと (step2)
https://github.com/irohafternoon/LeetCode/pull/18/files
https://github.com/Hurukawa2121/leetcode/pull/16/files
https://github.com/colorbox/leetcode/pull/30/files

std::exclusive_scanを初めて知った．C++17以降の機能で，累積和を計算する関数，これはぜひ使ってみたい．

https://cpprefjp.github.io/reference/numeric/exclusive_scan.html

全部走査して，みるたびに削除していたが，逆順で探すとストレートに足しながら処理できる．この方がスッキリ．

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> cumulative_sums(nums.size());
        exclusive_scan(nums.begin(), nums.end(), cumulative_sums.begin(), 0);
        cumulative_sums.push_back(cumulative_sums.back() + nums.back());

        unordered_map<int, int> sum_count;
        int valid_subarray_count = 0;

        for (size_t i = nums.size(); i >= 1; --i) {
            ++sum_count[cumulative_sums[i]];

            int target = cumulative_sums[i - 1] + k;
            if (sum_count.contains(target)) {
                valid_subarray_count += sum_count[target];
            }
        }

        return valid_subarray_count;
    }
};
```

exclusive_sums微妙に使いにくい...

もしくは，右端を固定して左端を探索することもできる．こうすると累積和の構築をやらないでよくて，1-passで解ける．

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sum_count;
        
        int current_sum = 0;
        ++sum_count[current_sum];
        
        int valid_subarray_count = 0;
        for (int num : nums) {
            current_sum += num;
            
            if (sum_count.contains(current_sum - k)) {
                valid_subarray_count += sum_count[current_sum - k];
            }
            ++sum_count[current_sum];
        }
        
        return valid_subarray_count;
    }
};
```

最終的にこれに落ち着いている人が多そう．自分もこれをよどみなく書けるようにする．
