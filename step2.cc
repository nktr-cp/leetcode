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
          if (!head) {
              return nullptr;
          }
  
          // 必要なノードだけをresultの連結リストに追加していく
          ListNode* result_head;
          ListNode* result_tail;
          result_head = result_tail = nullptr;
  
          // 元のノードのポインタ
          ListNode* current_node = head;
          // 元のリストから必要な要素をピックアップする
          while (current_node) {
              // 次のノードが存在しそれと値が一致する時は，
              // resultの連結リストには追加せず，ただ進める
              if (current_node->next && current_node->val == current_node->next->val) {
                  int duplicated_value = current_node->val;
                  while (current_node && current_node->val == duplicated_value) {
                      current_node = current_node->next;
                  }
                  continue;
              }
  
              // ここに到達したなら，resultのノードに追加して良い
              // 初期化済みかどうかで分岐が発生
              if (!result_head) {
                  result_head = result_tail = current_node;
              } else {
                  result_tail->next = current_node;
                  result_tail = result_tail->next;
              }
              current_node = current_node->next;
          }
  
          // 末尾のゴミを消す
          if (result_tail) {
              result_tail->next = nullptr;
          }
  
          return result_head;
      }
  };