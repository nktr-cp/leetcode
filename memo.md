## 考えたこと (step1)
第一印象は，まあ書いたことし典型的なやつなんだけど頭使うやつだな〜

大体方針は知っていて，3ノード間の関係を考えればよいのは覚えていた．
ワーキングメモリをふんだんに使って，最初に以下のようなコードを書いた．

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        ListNode *previous, *current, *next;
        previous = nullptr;
        current = head;
        next = current->next;

        while(current) {
            current->next = previous;
            previous = current;
            current = next;
        }

        return previous;
    }
};
```

すると，REでサニタイザに怒られる...

```bash
Line 24: Char 22: runtime error: member access within address 0x502000000070 with insufficient space for an object of type 'ListNode' (solution.cpp)
0x502000000070: note: pointer points here
 00 00 00 00  02 00 00 00 be be be be  90 00 00 00 20 50 00 00  02 02 00 00 10 00 00 00  10 00 00 00
              ^
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:33:22
```

その場でなんでサニタイザに怒られるのかを考えるも理解できず (SEGVとかならわかるのだけど)，泣く泣く書き直す．

とりあえず必要そうだと思っていたnextは，whileのスコープ内で十分なことに気づき，とりあえずstep1.ccを書く．
するとRunも通ってAccept (ここまで10分くらい)．

通ったので，バグったコードを見返してみる．

じっくりみるとnextの更新ができてないのが悪い．

何が起きるのかをstep by stepで考えてみると，

```cpp
a->next = a;
```

みたいなコードを繰り返すことになりそうなのだが，結局のところ何が原因でundefinedになるかを突き詰めるのは難しかった (printデバッグを入れるだけでもメモリアラインメントが変化するのか，再現せずただTLEになる)．

とにかく，変なコードを書くと変なエラーが出ることがあるので，落ち着いて書くようにする．

## 時間・空間計算量 (step1)
時間計算量O(len(list))，空間計算量O(1)
