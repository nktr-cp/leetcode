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
     bool hasCycle(ListNode *head) {
         std::set<ListNode*> visited;
         while (head && visited.count(head) == 0) {
             visited.insert(head);
             head = head->next;
         }
 
         return head != nullptr;
     }
 };