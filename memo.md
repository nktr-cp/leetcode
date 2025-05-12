## 考えたこと (step1)
二つ同時に動かすと二重ループになって計算が重くなってしまうので，一つを固定し，残りから，`target - nums[i]`を見つける．

残りの探索をする上で検索用のソート済みの配列があると嬉しい．今回は特定の要素をカウントしたいので，multisetを用意．

二分探索をかけて，見つかった場合のみそのインデックスを探す．そうすれば線形探索の回数は1回で済むので，十分高速に動作する．

つがいになる要素のインデックスは自分より先のインデックスから探してくることに注意．これは素数判定がO(sqrt(N))でできるのと同じような考え方で，先に登場したインデックス目線でペアを探せば良い．

この問題はテストケースがかなり優しくて，考えるべきケースがわかった．

## 時間・空間計算量 (step1)
Nをnums.lengthとする．

空間計算量は索引用の配列が支配的で，O(N)．

時間計算量は，ソートと対になる要素の検索でO(N logN)

## 考えたこと (step2)
https://hayapenguin.com/notes/LeetCode/1/TwoSum
https://github.com/huyfififi/coding-challenges/pull/1/files

読んだ．ハッシュマップ先に作ってしまうと重複するキーの扱いなど面倒な処理がいるなあと思っていたが，値を舐めながら逐次追加して対になる要素の検索をかけていくと，重複する要素によりtargetを構成する場合でもよしなにできる．

リファレンスの配列を用意してO(logN)で検索かければ解けるな，というのが簡単に見えるものあって，これは全然思いつかなかった．

解法はこれが一番ストレスなくかけて正解感がある．

ついでに，一回よぎったリファレンス用の配列を用意しない方法で実装してみた．

ペアの最初の要素だけで二分探索，という問題を解くとなるとstlの関数が使いづらそうなので，自分で二分探索を書く．

半開区間
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> number_and_index;
        for (int i = 0; i < nums.size(); ++i) {
            number_and_index.push_back({nums[i], i});
        }
        sort(number_and_index.begin(), number_and_index.end());

        for (int i = 0; i + 1 < number_and_index.size(); ++i) {
            int left = i + 1;
            int right = number_and_index.size();
            int to_find = target - number_and_index[i].first;
            while (right > left) {
                int mid = left + (right - left) / 2;
                if (number_and_index[mid].first > to_find) {
                    right = mid;
                } else if (number_and_index[mid].first < to_find) {
                    left = mid + 1;
                } else {
                    return vector<int>({number_and_index[i].second, number_and_index[mid].second});
                }
            }
        }
        assert(false);
        return vector<int>();
    }
};
```

開区間だと下:
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> number_and_index;
        for (int i = 0; i < nums.size(); ++i) {
            number_and_index.push_back({nums[i], i});
        }
        sort(number_and_index.begin(), number_and_index.end());

        for (int i = 0; i + 1 < number_and_index.size(); ++i) {
            int left = i;
            int right = number_and_index.size();
            int to_find = target - number_and_index[i].first;
            while (right - left > 1) {
                int mid = left + (right - left) / 2;
                if (number_and_index[mid].first > to_find) {
                    right = mid;
                } else if (number_and_index[mid].first < to_find) {
                    left = mid;
                } else {
                    return vector<int>({number_and_index[i].second, number_and_index[mid].second});
                }
            }
        }
        assert(false);
        return vector<int>();
    }
};
```

少なくともこの問題は，開区間で書くと±1がでなくて，すごく書きやすい．
