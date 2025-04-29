/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 #include <set>

 class Solution {
 public:
     ListNode *detectCycle(ListNode *head) {
         std::set<ListNode*> visited;
 
         while (head && !visited.contains(head)) {
             visited.insert(head);
             head = head->next;
         }
 
         return head;
     }
 };