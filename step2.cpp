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
      ListNode *findCollisionNode(ListNode *head) {
          ListNode* slow = head;
          ListNode* fast = head;
  
          while (fast && fast->next) {
              slow = slow->next;
              fast = fast->next->next;
  
              if (slow == fast) {
                  return slow;
              }
          }
  
          return nullptr;
      }
      ListNode *detectCycle(ListNode *head) {
          ListNode* collision_node = findCollisionNode(head);
          if (collision_node == nullptr) {
              return nullptr;
          }
  
          while (head != collision_node) {
              head = head->next;
              collision_node = collision_node->next;
          }
  
          return head;
      }
  };