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
  
          ListNode* result_head = nullptr;
          ListNode* result_tail = nullptr;
  
          ListNode* current_node = head;
          while (current_node) {
              if (current_node->next && current_node->val == current_node->next->val) {
                  int duplicated_value = current_node->val;
                  while (current_node && current_node->val == duplicated_value) {
                      current_node = current_node->next;
                  }
                  continue;
              }
  
              if (!result_head) {
                  result_head = result_tail = current_node;
              } else {
                  result_tail->next = current_node;
                  result_tail = result_tail->next;
              }
              current_node = current_node->next;
          }
  
          if (result_tail) {
              result_tail->next = nullptr;
          }
  
          return result_head;
      }
  };