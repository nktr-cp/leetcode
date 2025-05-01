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
      ListNode* deleteDuplicates(ListNode* head) {
          if (head == nullptr) {
              return nullptr;
          }
  
          // 現在着目しているノード
          ListNode* current_node = head;
          // 着目しているノードのnextに繋げたいノード
          ListNode* next_node = head->next;
          while (1) {
              // next_nodeが末端に到達するか，
              // 現在と異なる値を持つノードに到達するか，
              // どちらかまでループ
              while (next_node && current_node->val == next_node->val) {
                  next_node = next_node->next;
              }
              // 現在のノードの先を繋ぎ変え
              current_node->next = next_node;
  
              // もし繋ぎかえた先が末端なら，操作終了
              if (next_node == nullptr) {
                  break;
              }
  
              // 末端でないなら位置をずらして再度繋ぎ変え
              current_node = current_node->next;
              next_node = next_node->next;
          }
  
          return head;
      }
  };