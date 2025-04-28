/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 class Solution {
 public:
     // 遅いポインタと速いポインタを作る
     // 速いポインタは遅いポインタよりも1つづつ先を見る
     // もし循環があるのならどこかでこれらが一致する地点が出てくるはず
     bool hasCycle(ListNode *head) {
         ListNode* fast, slow;
         // 最初はどちらもheadで初期化
         fast = slow = head;
         // fastかfast->nextがnullptrになったら，末端があるということで
         // 循環がないことがわかる
         while (fast && fast->next) {
             // slowは1つ進める
             slow = slow->next;
             // fastは2つ進める
             fast = fast->next->next;

             if (slow == fast) {
              return true;
             }
         }
 
         return false;
     }
 };