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
         ListNode* current_node = head;
         ListNode* next_node = head->next;
         while (next_node) {
             while (next_node && current_node->val == next_node->val) {
                 next_node = next_node->next;
             }
 
             if (next_node == nullptr) {
                 current_node->next = nullptr;
                 return head;
             }
 
             current_node->next = next_node;
             current_node = current_node->next;
             next_node = next_node->next;
         }
 
         return head;
     }
 };