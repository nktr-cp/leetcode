## 考えたこと (step1)
おお，勉強会で見たやつだ，となった．

解法はやるだけ，と言う感じで，別解も特に思いつかないので，とりあえずstep2に進んでみる．

## 時間・空間計算量 (step1)
~~時間・空間計算量ともにO(s.length)~~

間違いだった．空間計算量はキーの数しかいらないので，O(1)．

## 考えたこと (step2)
https://github.com/colorbox/leetcode/pull/29/files
https://github.com/irohafternoon/LeetCode/pull/17/files
https://github.com/mura0086/arai60/pull/19/files

LRUキャッシュはよく聞かれるらしい．これは解いてPRだしてみよう．

https://leetcode.com/problems/lru-cache/description/

1-passで解けると言うのはそれはそう．たとえばmapを二つ用意して，

```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> char_to_count;
        unordered_map<char, int> first_index;

        for (size_t i = 0; i < s.size(); ++i) {
            ++char_to_count[s[i]];
            if (!first_index.contains(s[i])) {
                first_index[s[i]] = i;
            }
        }

        int target_index = INT_MAX;
        for (auto [c, count] : char_to_count) {
            if (count == 1) {
                target_index = min(target_index, first_index[c]);
            }
        }

        return target_index == INT_MAX ? -1 : target_index;
    }
};
```

あとは，queueに入れるやり方も紹介されていた．

https://github.com/colorbox/leetcode/pull/29/files#r1861430039

本筋とずれるが，classの中にstructが書けることを知らなかった...

これはとても便利，クラスメソッドだけで使うことを想定していて，中身を隠蔽したいことはしばしばあると思うので，ぜひこれから使ってみたい．

## 考えたこと (step3)
40秒くらいで書けるようになった．
