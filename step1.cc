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
  
          ListNode* current_node = head;
          while (current_node->next && current_node->val == current_node->next->val) {
              while (current_node->next && current_node->val == current_node->next->val) {
                  current_node = current_node->next;
              }
              if (!current_node->next) {
                  return nullptr;
              }
  
              current_node = current_node->next;
              head = current_node;
          }
  
          while (current_node->next) {
              ListNode* next_node = current_node->next;
              if (!next_node->next || next_node->val != next_node->next->val) {
                  current_node = next_node;
                  continue;
              }
  
              while (next_node->next && next_node->val == next_node->next->val) {
                  next_node = next_node->next;
              }
              next_node = next_node->next;
              current_node->next = next_node;
          }
  
          return head;
      }
  };