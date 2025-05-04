## 考えたこと (step1)
これはCでリストのライブラリ関数を作るときに書いたことがあるので，大体方針は知っていて，3ノード間の関係を考えればよいのは覚えていた．
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

その場でなんで (SEGVとかならまだわかるのだけど) サニタイザに怒られるのかを考えるも理解できず，泣く泣く書き直す．

とりあえず必要そうだと思って書いたnextは，whileのスコープ内で十分なことに気づき，とりあえずstep1.ccを書く，Accept (ここまで10分くらい)．

通ったので，バグったコードを見返してみる．

じっくりみるとnextの更新ができてないのが悪い．

何が起きるのかを手動でデバッグして考えてみると，

```cpp
a->next = a;
```

みたいなコードを繰り返すことになりそうなのだが，結局のところ何が原因でundefinedになるかを突き詰めるのは難しかった (printデバッグを入れるだけでもメモリアラインメントが変化するのか，再現せずただTLEになる)．

とにかく，変なコードを書くと変なエラーが出ることがあるので，あまりあたふたしないようにしたい．

## 時間・空間計算量 (step1)
時間計算量O(len(list))，空間計算量O(1)

## 考えたこと (step2)
まあロジックはいいと思うのだけど，いかんせん変数名がわかりにくく，特に`return previous`は処理が正しいことを直感的に理解できない，この点に注意して他の人のコードを見てみる．

コメント集を読んでみると，

https://discord.com/channels/1084280443945353267/1295357747545505833/1298524551592018003

こんなものを見つけ，これがとてもよく理解できた．確かに，作業のイメージは，前からぽこぽこノードを外して，新しい鎖にくっつける感じ (ここまで，step2.cc)．

再帰で書く解法が散見された．自分的にはこれが再帰なの？って感覚があったが，確かに読んでみるとすっきり書ける．

引っ掛かりポイントは，先頭を除いた先をreverseしたものを仮に貰えたとして，ひっくり返した先頭，つまり元のリストの末尾が返ってくるじゃん，という点だったが，reverseした後の末尾へのアクセスは，元の先頭のnextを保存しておくことで達成できることに気づき，納得した (下のコードみたいな話)．

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // base case
        if (!head || !head->next) {
            return head;
        }

        ListNode* reversed_tail = head;
        // ここで取っておけば，reverse後の末尾のノードへのアクセスが持っておける
        ListNode* child_tail = head->next;
        ListNode* reversed_head = this->reverseList(head->next);
        child_tail->next = reversed_tail;
        reversed_tail->next = nullptr;
        return reversed_head;
    }
};
```

ただ，自分はこの問題に再帰はちょっとやりすぎかなと感じた．

それと，そういえばこの問題はstackの分類に入っていた．

確かに，stackに全ノード詰めてpopしていけば，そもそもLIFOなんだから，逆順に取り出せてなんの頭も使わないでいい．

コーディング面接で確実に正しい答えを書いてくださいと言われれば，まあ確かにこれがいいかなと思った．

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
        std::stack<ListNode*> nodes;

        ListNode* current = head;
        while (current) {
            nodes.push(current);
            current = current->next;
        }

        ListNode dummy;
        ListNode *reversed_tail = &dummy;
        while (!nodes.empty()) {
            ListNode* next = nodes.top();
            nodes.pop();

            reversed_tail->next = next;
            reversed_tail = reversed_tail->next;
        }
        reversed_tail->next = nullptr;

        return dummy.next;
    }
};
```

## 考えたこと (step3)
3回書いてみて，いずれも1分くらい．

最初の認識はstep1に書いた通り，

>大体方針は知っていて，3ノード間の関係を考えればよいのは覚えていた．

こんな感じだったが，かなり印象が変わって，"新しく鎖を作る"というイメージを持つだけでこんなに問題に対しての複雑さの認識が変わるのかと感動した．
