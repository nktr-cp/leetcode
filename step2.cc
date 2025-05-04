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
      ListNode* reverseList(ListNode* head) {
          ListNode* unprocessed = head;
          ListNode* reversed_head = nullptr;
  
          while (unprocessed) {
              ListNode* next = unprocessed->next;
              unprocessed->next = reversed_head;
              reversed_head = unprocessed;
              unprocessed = next;
          }
  
          return reversed_head;
      }
  };