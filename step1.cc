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
      ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
          bool carry_flag = false;
  
          ListNode dummy = ListNode();
          ListNode* result_head = &dummy;
          ListNode* result_tail = result_head;
          while (l1 || l2) {
              int value_to_set;
              if (l1 && l2) {
                  value_to_set = l1->val + l2->val;
              } else if (l1) {
                  value_to_set = l1->val;
              } else {
                  value_to_set = l2->val;
              }
              if (carry_flag) {
                  value_to_set++;
                  carry_flag = false;
              }
  
              if (value_to_set >= 10) {
                  carry_flag = true;
                  value_to_set -= 10;
              }
  
              ListNode* new_node = new ListNode(value_to_set);
              result_tail->next = new_node;
              result_tail = result_tail->next;
              if (l1) {
                  l1 = l1->next;
              }
              if (l2) {
                  l2 = l2->next;
              }
          }
  
          if (carry_flag) {
              ListNode* new_node = new ListNode(1);
              result_tail->next = new_node;
          }
  
          return result_head->next;
      }
  };